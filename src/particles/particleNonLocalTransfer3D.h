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

#ifndef PARTICLE_NON_LOCAL_TRANSFER_3D_H
#define PARTICLE_NON_LOCAL_TRANSFER_3D_H

#include "core/globalDefs.h"
#include "multiBlock/localMultiBlockInfo3D.h"
#include "particles/multiParticleField3D.h"


namespace plb
{

template<class ParticleFieldT>
void copy (
    MultiParticleField3D<ParticleFieldT> const& from, Box3D const& fromDomain,
    MultiParticleField3D<ParticleFieldT>& to, Box3D const& toDomain );

/// Gather particles from a particle-field into a vector of particles,
/// on the main processor only.
template<typename T, template<typename U> class Descriptor, class ParticleFieldT>
void gatherParticles( MultiParticleField3D<ParticleFieldT>& particleField,
                      std::vector<Particle3D<T,Descriptor>*>& particles, Box3D domain );

/// Inject particle which are only provided on the main processor into
/// a particle-field.
template<typename T, template<typename U> class Descriptor, class ParticleFieldT>
void injectParticlesAtMainProc( std::vector<Particle3D<T,Descriptor>*>& particles,
                                MultiParticleField3D<ParticleFieldT>& particleField, Box3D domain );

} // namespace plb

#endif  // PARTICLE_NON_LOCAL_TRANSFER_3D_H
