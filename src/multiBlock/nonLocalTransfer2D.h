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

#ifndef NON_LOCAL_TRANSFER_2D_H
#define NON_LOCAL_TRANSFER_2D_H

#include "core/globalDefs.h"
#include "multiBlock/localMultiBlockInfo2D.h"
#include "multiBlock/multiDataField2D.h"
#include "multiBlock/multiBlockLattice2D.h"
#include <vector>


namespace plb
{


/// Determine pairs of domains associated to a data transfer between two blocks.
std::vector<Overlap2D> copyAllDataTransfer (
    SparseBlockStructure2D const& block1,
    SparseBlockStructure2D const& block2 );

/// Determine pairs of domains associated to a data transfer between domains on two blocks.
/** It is assumed that the two domains have the same extent.
 **/
std::vector<Overlap2D> copyDomainDataTransfer (
    SparseBlockStructure2D const& block1, Box2D block1Domain,
    SparseBlockStructure2D const& block2, Box2D block2Domain );

/// Equal-domain copy between two scalar-fields with different parallelization.
template<typename T>
void copyNonLocal (
    MultiScalarField2D<T> const& from, MultiScalarField2D<T>& to, Box2D const& domain );

/// Inter-domain copy between two scalar-fields.
/** The two blocks are not required to have same parallelization. If the two
 *  domains have different extent, the smaller domain is taken to be the valid one
 *  (this argument is reiterated independently in each space direction).
 **/
template<typename T>
void copy (
    MultiScalarField2D<T> const& from, Box2D const& fromDomain,
    MultiScalarField2D<T>& to, Box2D const& toDomain );

/// Equal-domain copy between two ntensor-fields with different parallelization.
template<typename T>
void copyNonLocal (
    MultiNTensorField2D<T> const& from, MultiNTensorField2D<T>& to, Box2D const& domain );

/// Inter-domain copy between two ntensor-fields.
/** The two blocks are not required to have same parallelization. If the two
 *  domains have different extent, the smaller domain is taken to be the valid one
 *  (this argument is reiterated independently in each space direction).
 **/
template<typename T>
void copy (
    MultiNTensorField2D<T> const& from, Box2D const& fromDomain,
    MultiNTensorField2D<T>& to, Box2D const& toDomain );

/// Equal-domain copy between two tensor-fields with different parallelization.
template<typename T, int nDim>
void copyNonLocal (
    MultiTensorField2D<T,nDim> const& from, MultiTensorField2D<T,nDim>& to, Box2D const& domain );

/// Inter-domain copy between two tensor-fields.
/** The two blocks are not required to have same parallelization. If the two
 *  domains have different extent, the smaller domain is taken to be the valid one
 *  (this argument is reiterated independently in each space direction).
 **/
template<typename T, int nDim>
void copy (
    MultiTensorField2D<T,nDim> const& from, Box2D const& fromDomain,
    MultiTensorField2D<T,nDim>& to, Box2D const& toDomain );

/// Equal-domain copy between two block-lattices with different parallelization.
template<typename T, template<typename U> class Descriptor>
void copyNonLocal (
    MultiBlockLattice2D<T,Descriptor> const& from,
    MultiBlockLattice2D<T,Descriptor>& to, Box2D const& domain,
    modif::ModifT whichContent );

/// Inter-domain copy between two block-lattices.
/** The two blocks are not required to have same parallelization. If the two
 *  domains have different extent, the smaller domain is taken to be the valid one
 *  (this argument is reiterated independently in each space direction).
 **/
template<typename T, template<typename U> class Descriptor>
void copy (
    MultiBlockLattice2D<T,Descriptor> const& from, Box2D const& fromDomain,
    MultiBlockLattice2D<T,Descriptor>& to, Box2D const& toDomain,
    modif::ModifT whichContent );

/// Inter-domain copy of the populations and external scalars between two block-lattices.
/** The two blocks are not required to have same parallelization. If the two
 *  domains have different extent, the smaller domain is taken to be the valid one
 *  (this argument is reiterated independently in each space direction).
 **/
template<typename T, template<typename U> class Descriptor>
void copyPopulations (
    MultiBlockLattice2D<T,Descriptor> const& from, Box2D const& fromDomain,
    MultiBlockLattice2D<T,Descriptor>& to, Box2D const& toDomain );

/// Inter-domain copy of the populations, external scalars, and dynamic variables between two block-lattices.
/** The two blocks are not required to have same parallelization. If the two
 *  domains have different extent, the smaller domain is taken to be the valid one
 *  (this argument is reiterated independently in each space direction).
 **/
template<typename T, template<typename U> class Descriptor>
void copyAll (
    MultiBlockLattice2D<T,Descriptor> const& from, Box2D const& fromDomain,
    MultiBlockLattice2D<T,Descriptor>& to, Box2D const& toDomain );

/// Inter-domain copy of all variables, and reconstitution of the dynamics objects, between two block-lattices.
/** The two blocks are not required to have same parallelization. If the two
 *  domains have different extent, the smaller domain is taken to be the valid one
 *  (this argument is reiterated independently in each space direction).
 **/
template<typename T, template<typename U> class Descriptor>
void copyRegenerate (
    MultiBlockLattice2D<T,Descriptor> const& from, Box2D const& fromDomain,
    MultiBlockLattice2D<T,Descriptor>& to, Box2D const& toDomain );

/// Inter-domain copy between two generic fields.
/** The two blocks are not required to have same parallelization. If the two
 *  domains have different extent, the smaller domain is taken to be the valid one
 *  (this argument is reiterated independently in each space direction).
 *  The two blocks must be of same kind. This condition is enforced by an assertion.
 **/
void copy_generic (
    MultiBlock2D const& from, Box2D const& fromDomain,
    MultiBlock2D& to, Box2D const& toDomain, modif::ModifT whichContent );

/// Equal-domain copy between two generic fields with different parallelization.
/** The two blocks must be of same kind. This condition is enforced by an assertion.  **/
void copyNonLocal_generic (
    MultiBlock2D const& from, MultiBlock2D& to,
    Box2D const& domain, modif::ModifT whichContent );

} // namespace plb

#endif  // NON_LOCAL_TRANSFER_2D_H
