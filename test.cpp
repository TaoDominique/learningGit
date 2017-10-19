#include <iostream>
#include <eigen3/Eigen/Dense>
#include <vector>

Eigen::Vector3f toEuler(const Eigen::Matrix3f& R)
{
  Eigen::Vector3f angles;
  angles(0) = atan2(R(2,1), R(2,2));
  angles(1) = atan2(-R(2,0),
		    (sqrt(std::pow(R(2,1), 2) + std::pow(R(2,2), 2))));
  angles(2) = atan2(R(1,0), R(0,0));
  
  return angles;
}
Eigen::Quaternionf Eul2Quat(const Eigen::Vector3f euler){
		Eigen::Quaternionf q;
		q = Eigen::AngleAxisf(euler[0], Eigen::Vector3f::UnitZ())
		* Eigen::AngleAxisf(euler[1],  Eigen::Vector3f::UnitX())
		* Eigen::AngleAxisf(euler[2], Eigen::Vector3f::UnitZ());
		
		return q;
}

//template <int N>
//using Vector = Eigen::Matrix<float, N, 1>;


int main(int argc, char* argv[] )
{
	
	Eigen::Quaternionf a;
	Eigen::Matrix3f mat;
	mat << 0,1,1,
		   1,1,0,
		   1,2,3;
	Eigen::Vector3f euler=toEuler(mat);
	a=Eul2Quat(euler);	
	
	std::cout << mat << std::endl;
}
