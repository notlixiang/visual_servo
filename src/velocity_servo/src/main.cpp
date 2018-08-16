#include <sstream>
#include "../../../devel/include/kinova_msgs/JointVelocity.h"
#include "ros/ros.h"
#include "sensor_msgs/JointState.h"
#include "std_msgs/String.h"

#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

#include <math.h>
#include <sensor_msgs/JointState.h>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>
#include <kdl/chain.hpp>
#include <kdl/chainfksolver.hpp>
#include <kdl/chainfksolverpos_recursive.hpp>
#include <kdl/chainiksolver.hpp>
#include <kdl/chainiksolverpos_nr.hpp>
#include <kdl/chainiksolvervel_pinv.hpp>
#include <kdl/chainjnttojacsolver.hpp>
#include <kdl/frames_io.hpp>
#include <kdl/jacobian.hpp>
#include <kdl/tree.hpp>
#include <kdl_parser/kdl_parser.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <../../../devel/include/keyboard/Key.h>

#include <key_def.h>

#include <geometry_msgs/Twist.h>
#include <tf/transform_listener.h>

#define PI 3.14159265359
#define stop_time 0.1
using namespace std;
using namespace KDL;
using namespace Eigen;

// string robotype="m1n6s300";
string robotype = "m1n6s300";
Frame F_dest;
JntArray q_now;
// JntArray q_tmp;
double d_v = 0.001;

double v_cart = 0.03;

Twist twist_cart;

int control_cnt = 0;

double trans_kp = 0;
double trans_ki = 0;
double trans_kd = 0;

double rot_kp = 0;
double rot_ki = 0;
double rot_kd = 0;

class CommandReceiver_keyboard {
 public:
  CommandReceiver_keyboard() {
    chatter_pub_0 = n.advertise<keyboard::Key>("keyup", 1000);
    sub = n.subscribe("keyboard/keydown", 1000,
                      &CommandReceiver_keyboard::callback, this);
  }
  void callback(const keyboard::Key& keymsg) {
    ROS_INFO("KEYBOARD_MSG_RECEIVED");
    //        printf("Q: %f %f %f %f %f %f
    //        \n",q_tmp(0),q_tmp(1),q_tmp(2),q_tmp(3),q_tmp(4),q_tmp(5));
    int code = keymsg.code;
    control_cnt = 0;

    SetToZero(twist_cart);

    switch (code) {
      case KEY_w:  // w
        F_dest.p(0) += d_v;
        twist_cart(0) = v_cart;
        break;
      case KEY_s:
        F_dest.p(0) -= d_v;
        twist_cart(0) = -v_cart;
        break;
      case KEY_a:
        F_dest.p(1) += d_v;
        twist_cart(1) = v_cart;
        break;
      case KEY_d:
        F_dest.p(1) -= d_v;
        twist_cart(1) = -v_cart;
        break;
      case KEY_UP:
        F_dest.p(2) += d_v;
        twist_cart(2) = v_cart;
        break;
      case KEY_DOWN:
        F_dest.p(2) -= d_v;
        twist_cart(2) = -v_cart;
        break;
      default:
        break;

        ROS_INFO("KEYBOARD_MSG_HANDLED");
    }
  }

 private:
  ros::NodeHandle n;
  ros::Publisher chatter_pub_0;
  ros::Subscriber sub;
};

class CommandReceiver_robo_vel {
 public:
  CommandReceiver_robo_vel() {
    // chatter_pub_0 = n.advertise<sensor_msgs::JointState>("joint_states_test",
    // 1000);
    sub = n.subscribe("m1n6s300_driver/out/joint_state", 1000,
                      &CommandReceiver_robo_vel::callback, this);
  }
  void callback(const sensor_msgs::JointState& kinova_states) {
    for (int i = 0; i < 6; i++) {
      q_now(i) = kinova_states.position[i];
      //            cout<<kinova_states<<endl;
    }
  }

 private:
  ros::NodeHandle n;
  ros::Publisher chatter_pub_0;
  ros::Subscriber sub;
};

Vector3f trans_velocity = Vector3f::Zero();
Vector3f rot_omega = Vector3f::Zero();
Vector3f translation_vector_pre_1 = Vector3f::Zero();
Vector3f rotation_vector_pre_1 = Vector3f::Zero();
Vector3f translation_vector_pre_2 = Vector3f::Zero();
Vector3f rotation_vector_pre_2 = Vector3f::Zero();

int robot_end_servo(const tf::StampedTransform transform, Twist& twist) {
  tf::Vector3 translation = transform.getOrigin();
  tf::Quaternion rotation = transform.getRotation();
  tfScalar rotation_angle = rotation.getAngle();
  tf::Vector3 rotation_axis = rotation.getAxis();

  Vector3f translation_vector(translation.getX(), translation.getY(),
                              translation.getZ());
  Vector3f rotation_vector(rotation_axis.getX(), rotation_axis.getY(),
                           rotation_axis.getZ());
  rotation_vector *= rotation_angle;

  Vector3f translation_error_p = translation_vector - translation_vector_pre_1;
  Vector3f translation_error_i = translation_vector;
  Vector3f translation_error_d = translation_vector -
                                 2 * translation_vector_pre_1 +
                                 translation_vector_pre_2;

  Vector3f rotation_error_p = rotation_vector - rotation_vector_pre_1;
  Vector3f rotation_error_i = rotation_vector;
  Vector3f rotation_error_d =
      rotation_vector - 2 * rotation_vector_pre_1 + rotation_vector_pre_2;

  trans_velocity += trans_kp * translation_error_p +
                    trans_ki * translation_error_i +
                    trans_kd * translation_error_d;
  rot_omega += rot_kp * rotation_error_p + rot_ki * rotation_error_i +
               rot_kd * rotation_error_d;

  translation_vector_pre_2 = translation_vector_pre_1;
  rotation_vector_pre_2 = rotation_vector_pre_1;
  translation_vector_pre_1 = translation_vector;
  rotation_vector_pre_1 = rotation_vector;

  twist(0) = trans_velocity(0);
  twist(1) = trans_velocity(1);
  twist(2) = trans_velocity(2);

  twist(3) = rot_omega(0);
  twist(4) = rot_omega(1);
  twist(5) = rot_omega(2);

  return 0;
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "jaco_vel_move_real");

  ros::NodeHandle n;

  ros::Publisher robot_joint_velocity_publisher =
      n.advertise<kinova_msgs::JointVelocity>(
          "m1n6s300_driver/in/joint_velocity", 1000);
  tf::TransformListener tf_listener;

  int ros_loop_rate = 100;
  int control_cnt_MAX = ros_loop_rate * stop_time;
  ros::Rate loop_rate(ros_loop_rate);

  kinova_msgs::JointVelocity JointVelPub;

  //    JointStatePub.name.resize(9);
  //    JointStatePub.position.resize(9);

  //    JointStatePub.name[0]=robotype+"_joint_1";
  //    JointStatePub.name[1]=robotype+"_joint_2";
  //    JointStatePub.name[2]=robotype+"_joint_3";
  //    JointStatePub.name[3]=robotype+"_joint_4";
  //    JointStatePub.name[4]=robotype+"_joint_5";
  //    JointStatePub.name[5]=robotype+"_joint_6";
  //    JointStatePub.name[6]=robotype+"_joint_finger_1";
  //    JointStatePub.name[7]=robotype+"_joint_finger_2";
  //    JointStatePub.name[8]=robotype+"_joint_finger_3";

  //    for(int i=0;i<9;i++)
  //    {
  //        JointStatePub.position[i]=0;
  //    }

  //    for(int i=0;i<6;i++)
  //    {
  //        twist_cart(i)=0;
  //    }
  SetToZero(twist_cart);
  // twist_cart.Zero();

  double cnt = 0;

  int cycleperiod = 2;

  KDL::Tree my_tree;
  KDL::Chain my_chain;
  unsigned int joint_num;
  KDL::JntArray jointpositions;
  KDL::JntArray jointvelocitys;
  if (!kdl_parser::treeFromFile(
          "./src/kinova-ros-master/kinova_description/urdf/" + robotype +
              "_standalone.urdf",
          my_tree)) {
    ROS_ERROR("Failed to construct kdl tree");
  }
  if (!my_tree.getChain(robotype + "_link_base", robotype + "_end_effector",
                        my_chain)) {
    ROS_ERROR("Failed to convert to chain");
  }

  joint_num = my_chain.getNrOfJoints();

  jointpositions = KDL::JntArray(joint_num);
  jointvelocitys = KDL::JntArray(joint_num);

  ChainFkSolverPos_recursive fksolver1(my_chain);  // Forward position solver
  ChainIkSolverVel_pinv iksolver1v(my_chain);      // Inverse velocity solver
  ChainIkSolverPos_NR iksolver1(
      my_chain, fksolver1, iksolver1v, 100,
      1e-6);  // Maximum 100 iterations, stop at accuracy 1e-6

  // Creation of jntarrays:
  JntArray q(joint_num);
  JntArray q_init(joint_num);

  JntArray q_next(joint_num);
  JntArray q_vel(joint_num);
  JntArray q_vel_0(joint_num);
  Frame F_init;
  Frame F_now;
  //    Frame F_dest=...;

  //    int ret = iksolverpos.CartToJnt(q_init,F_dest,q);

  //    for(int i=0;i<6;i++)
  //    {
  //        q_init(i)=0;
  //        q_now(i)=0;
  //    }

  q_init(0) = 1;
  q_init(1) = 1;
  q_init(2) = 1;
  q_init(3) = 1;
  q_init(4) = 1;
  q_init(5) = 1;

  q_now.resize(joint_num);

  // q_init(0)=26188.316285;
  // q_init(1)=-24565.820627;
  // q_init(2)=40093.660688 ;
  // q_init(3)=-102626.646365 ;
  // q_init(4)=27251.082089 ;
  // q_init(5)=-2661.168053;

  //    q_now=q_init;

  if (fksolver1.JntToCart(q_init, F_init) != 0) {
    ROS_ERROR("Failed to solve init cart");
  }

  cout << F_init.p << endl << F_init.M << endl;
  F_dest = F_init;

  CommandReceiver_keyboard command_receiver_keyboard;  //监视Topic中命令
  CommandReceiver_robo_vel command_receiver_robo_vel;  // refresh q_now
  while (ros::ok()) {
    tf::StampedTransform transform;
    try {
      tf_listener.lookupTransform("ee_target", "ee_link", ros::Time(0),
                                  transform);
    } catch (tf::TransformException& ex) {
      ROS_ERROR("%s", ex.what());
      //          ros::Duration(1.0).sleep();
      //          continue;
    }

    ROS_INFO("twist_cart: %f %f %f %f %f %f ", twist_cart(0), twist_cart(1),
             twist_cart(2), twist_cart(3), twist_cart(4), twist_cart(5));

    if (iksolver1v.CartToJnt(q_now, twist_cart, q_vel_0) != 0) {
      ROS_ERROR("Failed to solve jnt");
    } else {
      for (int i = 0; i < 6; i++) {
        q_vel(i) = q_vel_0(i) * 180 / 3.14159;
      }
      if (control_cnt > control_cnt_MAX) {
        SetToZero(twist_cart);
        for (int i = 0; i < 6; i++) {
          q_vel(i) = 0;
        }
      }

      JointVelPub.joint1 = q_vel(0);
      JointVelPub.joint2 = q_vel(1);
      JointVelPub.joint3 = q_vel(2);
      JointVelPub.joint4 = q_vel(3);
      JointVelPub.joint5 = q_vel(4);
      JointVelPub.joint6 = q_vel(5);

      //        cout<<F_dest.p<<endl;
      // JointStatePub.position[1]=;
      //        ROS_INFO("%d",nj);
      //        ROS_INFO("%f",angle);

      robot_joint_velocity_publisher.publish(JointVelPub);
    }
    control_cnt += 1;
    cnt += 1;
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}