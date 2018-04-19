#ifndef K_MATRIX_BASE_H
#define K_MATRIX_BASE_H

#include <map>
#include <functional>

/* The qSqFncts argument to calculate(..) holds a list of function pointers
 * that return the scattering momentum squared in units of the reference mass
 * squared
 *
 * 	q_cm,i^2 / m_ref^2
 *
 * for channel index i, where the channel index ordering is the same as that
 * for the chan and chanp arguments, i.e. the two relevant qSq functions are
 * accessible through
 *
 * 	qSqFcts[chan]	and	qSqFcts[chanp]
 */


class KtildeMatrixBase
{

 public:

    virtual ~KtildeMatrixBase() {};

    virtual double calculate(uint Jtimestwo, 
                     uint Lp, uint Sptimestwo, uint chanp,
                     uint L, uint Stimestwo, uint chan,
                     double Ecm_over_mref,
		     const std::vector<std::function<double(double)>>& qSqFcts) const = 0;

    virtual bool isZero(uint Jtimestwo, 
                uint Lp, uint Sptimestwo, uint chanp,
                uint L, uint Stimestwo, uint chan) const = 0;

};

#endif
