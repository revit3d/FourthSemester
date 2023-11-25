#include <complex>
#include <vector>
#include <limits>
#include <array>

namespace Equations
{
    template < typename T >
    std::pair < bool, std::vector < std::complex < T > > > quadratic(const std::array < std::complex < T >, 3 >& coeff)
    {
        constexpr T eps = 32 * std::numeric_limits < T >::epsilon();
        if (std::norm(coeff[2]) < eps)
        {
            if (std::norm(coeff[1]) < eps)
                return std::make_pair(std::norm(coeff[0]) >= eps, std::vector < std::complex < T > >());
            else
                return std::make_pair(true, std::vector < std::complex < T > >{-coeff[0] / coeff[1]});
        }
        else  
        {
            std::complex < T > D = coeff[1] * coeff[1] - std::complex < T >(4) * coeff[0] * coeff[2];
            std::vector < std::complex < T > > ans;
            ans.push_back((-coeff[1] + std::sqrt(D)) / (std::complex < T >(2) * coeff[2]));
            ans.push_back((-coeff[1] - std::sqrt(D)) / (std::complex < T >(2) * coeff[2]));
            return std::make_pair(true, ans);
        }
    }
}