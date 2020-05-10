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

/*
 * Several utilities -- header file.
 */

#ifndef GRID_REFINEMENT_UTIL_3D_H
#define GRID_REFINEMENT_UTIL_3D_H

#include "core/geometry3D.h"
#include "core/globalDefs.h"
#include "multiBlock/multiBlockLattice3D.h"

#include "gridRefinement/couplingInterfaceGenerator3D.h"

#include <memory>

namespace plb
{

template<typename T, template <typename U> class Descriptor,
         template<typename T2, template<typename U2> class Descriptor2> class Engine>
std::auto_ptr<MultiBlockLattice3D<T,Descriptor> > exportLatticeToSingleGridLevel(
    MultiLevelCoupling3D<T,Descriptor,Engine>& lattices, plint exportLevel,
    Box3D const& referenceDomain, plint levelOfReferenceDomain);

}  // namespace plb

#endif  // GRID_REFINEMENT_UTIL_3D_H
