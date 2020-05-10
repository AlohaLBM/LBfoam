/* This file is part of the Palabos library.
 *
 * Copyright (C) 2011-2017 FlowKit Sarl
 * Route d'Oron 2
 * 1010 Lausanne, Switzerland
 * E-mail contact: contact@flowkit.com
 *
 * The most recent release of Palabos can be downloaded at 
 * <http://www.palabos.org/>
 *
 * The library Palabos is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * The library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/** \file
 * Descriptor for nearest-neighbor 2D lattices -- generic code.
 **/
#ifndef EXTENDED_NEIGHBORHOOD_LATTICES_2D_HH
#define EXTENDED_NEIGHBORHOOD_LATTICES_2D_HH

#include "latticeBoltzmann/extendedNeighborhoodLattices2D.h"

namespace plb {

namespace descriptors {
    // D2Q37 ////////////////////////////////////////////////////////////

    template<typename T>
    const T D2Q37Constants<T>::invD = (T)1 / (T) d;

    template<typename T>
    const int D2Q37Constants<T>::vicinity = 3;

    template<typename T>
    const int D2Q37Constants<T>::c
        [D2Q37Constants<T>::q][D2Q37Constants<T>::d] =
        {
            { 0, 0},
            {-1, 3}, {-1, 2}, {-1, 1}, {-2, 2}, {-2, 1}, {-3, 1}, {-1, 0}, {-2, 0}, {-3, 0},
            {-3,-1}, {-2,-1}, {-1,-1}, {-2,-2}, {-1,-2}, {-1,-3}, { 0,-1}, { 0,-2}, { 0,-3},
            
            { 1,-3}, { 1,-2}, { 1,-1}, { 2,-2}, { 2,-1}, { 3,-1}, { 1, 0}, { 2, 0}, { 3, 0},
            { 3, 1}, { 2, 1}, { 1, 1}, { 2, 2}, { 1, 2}, { 1, 3}, { 0, 1}, { 0, 2}, { 0, 3}
        };

    template<typename T>
    const int D2Q37Constants<T>::cNormSqr[D2Q37Constants<T>::q] =
        { 
            0, 
            10, 5, 2, 8, 5, 10, 1, 4, 9,
            10, 5, 2, 8, 5, 10, 1, 4, 9,
            10, 5, 2, 8, 5, 10, 1, 4, 9,
            10, 5, 2, 8, 5, 10, 1, 4, 9
        };

    template<typename T>
    const T D2Q37Constants<T>::t[D2Q37Constants<T>::q] =
        {
            0.23315066913235250228650,
            0.00028341425299419821740, 0.00535304900051377523273, 0.05766785988879488203006, 0.00101193759267357547541, 0.00535304900051377523273, 0.00028341425299419821740, 0.10730609154221900241246, 0.01420821615845075026469, 0.00024530102775771734547,
            0.00028341425299419821740, 0.00535304900051377523273, 0.05766785988879488203006, 0.00101193759267357547541, 0.00535304900051377523273, 0.00028341425299419821740, 0.10730609154221900241246, 0.01420821615845075026469, 0.00024530102775771734547,
            0.00028341425299419821740, 0.00535304900051377523273, 0.05766785988879488203006, 0.00101193759267357547541, 0.00535304900051377523273, 0.00028341425299419821740, 0.10730609154221900241246, 0.01420821615845075026469, 0.00024530102775771734547,
            0.00028341425299419821740, 0.00535304900051377523273, 0.05766785988879488203006, 0.00101193759267357547541, 0.00535304900051377523273, 0.00028341425299419821740, 0.10730609154221900241246, 0.01420821615845075026469, 0.00024530102775771734547
        };

    template<typename T>
    const T D2Q37Constants<T>::cs2 = 1./ (1.19697977039307435897239*1.19697977039307435897239);

    template<typename T>
    const T D2Q37Constants<T>::invCs2 = 1.19697977039307435897239*1.19697977039307435897239;

    template<typename T>
    const char D2Q37Descriptor<T>::name[] = "D2Q37";

    template<typename T>
    const char ForcedD2Q37Descriptor<T>::name[] = "ForcedD2Q37";

    // Added by Mehdi Ataei as part of LBfoam project

    // Extended D2Q9 ////////////////////////////////////////////////////////////

    template<typename T>
    const T ExtendedD2Q9Constants<T>::invD = (T)1 / (T) d;

    template<typename T>
    const int ExtendedD2Q9Constants<T>::vicinity = 3;

    template<typename T>
    const int ExtendedD2Q9Constants<T>::c
        [ExtendedD2Q9Constants<T>::q][ExtendedD2Q9Constants<T>::d] =
        {
            { 0, 0},
            {-1, 1}, {-1, 0}, {-1,-1}, { 0,-1},
            { 1,-1}, { 1, 0}, { 1, 1}, { 0, 1}
        };

    template<typename T>
    const int ExtendedD2Q9Constants<T>::cNormSqr[ExtendedD2Q9Constants<T>::q] =
        { 0, 2, 1, 2, 1, 2, 1, 2, 1 };

    template<typename T>
    const T ExtendedD2Q9Constants<T>::t[ExtendedD2Q9Constants<T>::q] =
        {
            (T)4/(T)9, (T)1/(T)36, (T)1/(T)9, (T)1/(T)36, (T)1/(T)9,
                       (T)1/(T)36, (T)1/(T)9, (T)1/(T)36, (T)1/(T)9
        };

    template<typename T>
    const T ExtendedD2Q9Constants<T>::cs2 = (T)1 / (T)3;

    template<typename T>
    const T ExtendedD2Q9Constants<T>::invCs2 = (T)3;

    template<typename T>
    const char ExtendedForcedD2Q9Descriptor<T>::name[] = "ExtendedForcedD2Q9";


}  // namespace descriptors

}  // namespace plb

#endif
