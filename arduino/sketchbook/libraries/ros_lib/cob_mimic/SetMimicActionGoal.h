#ifndef _ROS_cob_mimic_SetMimicActionGoal_h
#define _ROS_cob_mimic_SetMimicActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "cob_mimic/SetMimicGoal.h"

namespace cob_mimic
{

  class SetMimicActionGoal : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalID goal_id;
      cob_mimic::SetMimicGoal goal;

    SetMimicActionGoal():
      header(),
      goal_id(),
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->goal_id.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->goal_id.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "cob_mimic/SetMimicActionGoal"; };
    const char * getMD5(){ return "e485d95f9cd2074d9c787ea86b8144e2"; };

  };

}
#endif