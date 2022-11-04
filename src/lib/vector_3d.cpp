#include <iostream>

#include "lib/vector_3d.h"

static constexpr double max_diff{0.05};

Vector3D::Vector3D(double x, double y, double z) : 
    x{x}, y{y}, z{z} {
    this->pose_msg.pose.position.x = x;
    this->pose_msg.pose.position.y = y;
    this->pose_msg.pose.position.z = z;
}

geometry_msgs::PoseStamped Vector3D::to_pose() {
    return this->pose_msg;
}

bool Vector3D::operator ==(const geometry_msgs::PoseStamped other_pose) const {
    return (std::abs(this->x - other_pose.pose.position.x) < max_diff) and
           (std::abs(this->y - other_pose.pose.position.y) < max_diff) and
           (std::abs(this->z - other_pose.pose.position.z) < max_diff);
}

bool Vector3D::operator !=(const geometry_msgs::PoseStamped other_pose) const {
    return (std::abs(this->x - other_pose.pose.position.x) > max_diff) or
           (std::abs(this->y - other_pose.pose.position.y) > max_diff) or
           (std::abs(this->z - other_pose.pose.position.z) > max_diff);
}