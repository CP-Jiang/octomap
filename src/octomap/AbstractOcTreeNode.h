#ifndef OCTOMAP_ABSTRACT_OCTREE_NODE_H
#define OCTOMAP_ABSTRACT_OCTREE_NODE_H

// $Id$

/**
* Octomap:
* A  probabilistic, flexible, and compact 3D mapping library for robotic systems.
* @author K. M. Wurm, A. Hornung, University of Freiburg, Copyright (C) 2009.
* @see http://octomap.sourceforge.net/
* License: GNU GPL v2, http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt
*/

/*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
* or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
* for more details.
*
* You should have received a copy of the GNU General Public License along
* with this program; if not, write to the Free Software Foundation, Inc.,
* 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#include "octomap_types.h"

namespace octomap {

  /**
   * Interface of OcTreeNodes. Every Node used in an AbstractOcTree has to implement it.
   */
  class AbstractOcTreeNode {

  public:

    AbstractOcTreeNode() {};
    virtual ~AbstractOcTreeNode() {};

    // children ------

    /// \return a pointer to the i th child of the node. The child needs to exist.
    virtual AbstractOcTreeNode* getChild(unsigned int i) = 0;
    /// \return a const pointer to the i th child of the node. The child needs to exist.
    virtual const AbstractOcTreeNode* getChild(unsigned int i) const = 0;
    virtual bool createChild(unsigned int i) = 0;
    /// \return true if the i th child exists
    virtual bool childExists(unsigned int i) const = 0;
    /// \return true if the node has at least one child
    virtual bool hasChildren() const = 0;

    // occupancy  ----
 
    virtual void integrateHit() = 0;
    virtual void integrateMiss() = 0;
    virtual bool isOccupied() const = 0;
    /// updates the occupancy of an inner node according to its children
    virtual void updateOccupancyChildren() = 0;

    // clamping ------
    virtual bool collapsible() const = 0;
    virtual bool isClamped() const = 0;
    virtual void convertToBinary() = 0;


  protected:

  };


} // end namespace



#endif
