#ifndef _ROS_SERVICE_StopLightMode_h
#define _ROS_SERVICE_StopLightMode_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cob_light
{

static const char STOPLIGHTMODE[] = "cob_light/StopLightMode";

  class StopLightModeRequest : public ros::Msg
  {
    public:
      uint64_t track_id;

    StopLightModeRequest():
      track_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        uint64_t real;
        uint32_t base;
      } u_track_id;
      u_track_id.real = this->track_id;
      *(outbuffer + offset + 0) = (u_track_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_track_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_track_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_track_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->track_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        uint64_t real;
        uint32_t base;
      } u_track_id;
      u_track_id.base = 0;
      u_track_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_track_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_track_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_track_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->track_id = u_track_id.real;
      offset += sizeof(this->track_id);
     return offset;
    }

    const char * getType(){ return STOPLIGHTMODE; };
    const char * getMD5(){ return "1f4aa1f5e9801bce0a14ea1582303637"; };

  };

  class StopLightModeResponse : public ros::Msg
  {
    public:
      uint8_t active_mode;
      uint8_t active_priority;
      uint64_t track_id;

    StopLightModeResponse():
      active_mode(0),
      active_priority(0),
      track_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->active_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->active_mode);
      *(outbuffer + offset + 0) = (this->active_priority >> (8 * 0)) & 0xFF;
      offset += sizeof(this->active_priority);
      union {
        uint64_t real;
        uint32_t base;
      } u_track_id;
      u_track_id.real = this->track_id;
      *(outbuffer + offset + 0) = (u_track_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_track_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_track_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_track_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->track_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->active_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->active_mode);
      this->active_priority =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->active_priority);
      union {
        uint64_t real;
        uint32_t base;
      } u_track_id;
      u_track_id.base = 0;
      u_track_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_track_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_track_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_track_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->track_id = u_track_id.real;
      offset += sizeof(this->track_id);
     return offset;
    }

    const char * getType(){ return STOPLIGHTMODE; };
    const char * getMD5(){ return "44b6bbe013cafd2810aef2660066a5b8"; };

  };

  class StopLightMode {
    public:
    typedef StopLightModeRequest Request;
    typedef StopLightModeResponse Response;
  };

}
#endif
