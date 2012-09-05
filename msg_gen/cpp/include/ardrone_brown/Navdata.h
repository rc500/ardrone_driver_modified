/* Auto-generated by genmsg_cpp for file /home/rujian/fuerte_workspace/ardrone_brown/msg/Navdata.msg */
#ifndef ARDRONE_BROWN_MESSAGE_NAVDATA_H
#define ARDRONE_BROWN_MESSAGE_NAVDATA_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"

#include "std_msgs/Header.h"

namespace ardrone_brown
{
template <class ContainerAllocator>
struct Navdata_ {
  typedef Navdata_<ContainerAllocator> Type;

  Navdata_()
  : header()
  , batteryPercent(0.0)
  , rotX(0.0)
  , rotY(0.0)
  , rotZ(0.0)
  , altd(0)
  , vx(0.0)
  , vy(0.0)
  , vz(0.0)
  , tm(0.0)
  {
  }

  Navdata_(const ContainerAllocator& _alloc)
  : header(_alloc)
  , batteryPercent(0.0)
  , rotX(0.0)
  , rotY(0.0)
  , rotZ(0.0)
  , altd(0)
  , vx(0.0)
  , vy(0.0)
  , vz(0.0)
  , tm(0.0)
  {
  }

  typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
   ::std_msgs::Header_<ContainerAllocator>  header;

  typedef float _batteryPercent_type;
  float batteryPercent;

  typedef float _rotX_type;
  float rotX;

  typedef float _rotY_type;
  float rotY;

  typedef float _rotZ_type;
  float rotZ;

  typedef int32_t _altd_type;
  int32_t altd;

  typedef float _vx_type;
  float vx;

  typedef float _vy_type;
  float vy;

  typedef float _vz_type;
  float vz;

  typedef float _tm_type;
  float tm;


  typedef boost::shared_ptr< ::ardrone_brown::Navdata_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ardrone_brown::Navdata_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct Navdata
typedef  ::ardrone_brown::Navdata_<std::allocator<void> > Navdata;

typedef boost::shared_ptr< ::ardrone_brown::Navdata> NavdataPtr;
typedef boost::shared_ptr< ::ardrone_brown::Navdata const> NavdataConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::ardrone_brown::Navdata_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::ardrone_brown::Navdata_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace ardrone_brown

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::ardrone_brown::Navdata_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::ardrone_brown::Navdata_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::ardrone_brown::Navdata_<ContainerAllocator> > {
  static const char* value() 
  {
    return "0e8fc2a4b7f377e10e22371c42bfd78b";
  }

  static const char* value(const  ::ardrone_brown::Navdata_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x0e8fc2a4b7f377e1ULL;
  static const uint64_t static_value2 = 0x0e22371c42bfd78bULL;
};

template<class ContainerAllocator>
struct DataType< ::ardrone_brown::Navdata_<ContainerAllocator> > {
  static const char* value() 
  {
    return "ardrone_brown/Navdata";
  }

  static const char* value(const  ::ardrone_brown::Navdata_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::ardrone_brown::Navdata_<ContainerAllocator> > {
  static const char* value() 
  {
    return "Header header\n\
\n\
# 0 means no battery, 100 means full battery\n\
float32 batteryPercent\n\
\n\
# left/right tilt in degrees (rotation about the X axis)\n\
float32 rotX\n\
\n\
# forward/backward tilt in degrees (rotation about the Y axis)\n\
float32 rotY\n\
\n\
# orientation in degrees (rotation about the Z axis)\n\
float32 rotZ\n\
\n\
# estimated altitude (cm)\n\
int32 altd\n\
\n\
# linear velocity (mm/sec)\n\
float32 vx\n\
\n\
# linear velocity (mm/sec)\n\
float32 vy\n\
\n\
# linear velocity (mm/sec)\n\
float32 vz\n\
\n\
#time stamp\n\
float32 tm\n\
\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.secs: seconds (stamp_secs) since epoch\n\
# * stamp.nsecs: nanoseconds since stamp_secs\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
";
  }

  static const char* value(const  ::ardrone_brown::Navdata_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct HasHeader< ::ardrone_brown::Navdata_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct HasHeader< const ::ardrone_brown::Navdata_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::ardrone_brown::Navdata_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.header);
    stream.next(m.batteryPercent);
    stream.next(m.rotX);
    stream.next(m.rotY);
    stream.next(m.rotZ);
    stream.next(m.altd);
    stream.next(m.vx);
    stream.next(m.vy);
    stream.next(m.vz);
    stream.next(m.tm);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct Navdata_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ardrone_brown::Navdata_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::ardrone_brown::Navdata_<ContainerAllocator> & v) 
  {
    s << indent << "header: ";
s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "batteryPercent: ";
    Printer<float>::stream(s, indent + "  ", v.batteryPercent);
    s << indent << "rotX: ";
    Printer<float>::stream(s, indent + "  ", v.rotX);
    s << indent << "rotY: ";
    Printer<float>::stream(s, indent + "  ", v.rotY);
    s << indent << "rotZ: ";
    Printer<float>::stream(s, indent + "  ", v.rotZ);
    s << indent << "altd: ";
    Printer<int32_t>::stream(s, indent + "  ", v.altd);
    s << indent << "vx: ";
    Printer<float>::stream(s, indent + "  ", v.vx);
    s << indent << "vy: ";
    Printer<float>::stream(s, indent + "  ", v.vy);
    s << indent << "vz: ";
    Printer<float>::stream(s, indent + "  ", v.vz);
    s << indent << "tm: ";
    Printer<float>::stream(s, indent + "  ", v.tm);
  }
};


} // namespace message_operations
} // namespace ros

#endif // ARDRONE_BROWN_MESSAGE_NAVDATA_H

