#ifndef icr_server_h___
#define icr_server_h___

#include "ros/ros.h"
#include "icr.h"
#include "../srv_gen/cpp/include/icr/compute_icr.h"
#include "../srv_gen/cpp/include/icr/load_object.h"
#include "../srv_gen/cpp/include/icr/add_fingers.h"
#include "../srv_gen/cpp/include/icr/set_finger_parameters.h"
#include <boost/thread/mutex.hpp>

class IcrServer
{
private:

  ros::NodeHandle nh_;
  ros::ServiceServer compute_icr_service_;
  ros::ServiceServer load_wfront_obj_service_;
  ros::ServiceServer add_fingers_service_;
  ros::ServiceServer set_finger_parameters_service_;
  ICR::ObjectLoader* obj_loader_;
  ICR::FParamList* finger_parameters_;
  boost::mutex data_mutex_;

public:
 
  IcrServer();
  ~IcrServer();

  bool computeIcr(icr::compute_icr::Request  &req, icr::compute_icr::Response &res);
  bool loadWfrontObj(icr::load_object::Request  &req, icr::load_object::Response &res);
  bool addFingers(icr::add_fingers::Request &req, icr::add_fingers::Response &res); 
  bool setFingerParameters(icr::set_finger_parameters::Request &req, icr::set_finger_parameters::Response &res);

};



#endif
