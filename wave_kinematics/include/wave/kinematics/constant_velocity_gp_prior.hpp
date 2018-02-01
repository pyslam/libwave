#ifndef WAVE_CONSTANT_VELOCITY_GP_PRIOR_HPP
#define WAVE_CONSTANT_VELOCITY_GP_PRIOR_HPP

#include <Eigen/Core>
#include <unsupported/Eigen/MatrixFunctions>
#include "wave/geometry/transformation.hpp"
#include "wave/utils/math.hpp"

namespace wave_kinematics {

struct ConstantVelocityPrior {
    using Mat12 = Eigen::Matrix<double, 12, 12>;

    ConstantVelocityPrior() = delete;
    ConstantVelocityPrior(const double &tk, const double &tkp1, const double* tau, const wave::Mat6& Qc, const wave::Mat6& inv_Qc);

    const double &tk;
    const double &tkp1;
    const double *tau;
    const wave::Mat6 &Qc;
    const wave::Mat6 &inv_Qc;

    Mat12 t_mat, inv_covar;

    /// Function to generate transition matrix
    void calculateTransitionMatrix(Mat12 &transition, const double &t1, const double &t2);
    void calculateTransitionMatrix();

    /// Functions for linearized covariance
    void calculateLinInvCovariance(Mat12 &covariance, const double &t1, const double &t2);
    void calculateLinCovariance(Mat12 &covariance, const double &t1, const double &t2);
    void calculateLinInvCovariance();

    //todo(ben) figure out what to call these
    /// Functions to calculate hat and candle matrices
    void calculateStuff(Mat12 &hat, Mat12 &candle);

    void calculateCandle(Mat12 &candle);

};
}

#endif //WAVE_CONSTANT_VELOCITY_GP_PRIOR_HPP