#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */

	Eigen::VectorXd rmse(4);
	rmse << 0,0,0,0;

    // TODO: YOUR CODE HERE

	// check the validity of the following inputs:
	//  * the estimation vector size should not be zero
	//  * the estimation vector size should equal ground truth vector size
	// ... your code here
	if(estimations.size()==0||estimations.size()!=ground_truth.size()){
	    std::cout<<"Error: Estimations size is zero or not equal to ground truth size";
	    return rmse;
	}
	
	Eigen::VectorXd residual;
  Eigen::VectorXd residual_sq;
	//accumulate squared residuals
	for(int i=0; i < estimations.size(); ++i){
        // ... your code here
        VectorXd residual = estimations[i]-ground_truth[i];
        VectorXd residual_sq = residual.array()*residual.array();
        rmse+=residual_sq;
	}

	//calculate the mean
	// ... your code here
	rmse = rmse/estimations.size();

	//calculate the squared root
	// ... your code here
	rmse = rmse.array().sqrt();

	//return the result
	return rmse;
}
