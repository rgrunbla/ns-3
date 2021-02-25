/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2020 INRIA
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Rémy Grünblatt <remy@grunblatt.org>
 */
#include "quaternion.h"
#include "fatal-error.h"
#include "log.h"
#include <cmath>
#include <sstream>
#include <tuple>

/**
 * \file
 * \ingroup attribute_Quaternion
 * ns3::Quaternion attribute value implementations.
 */

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("Quaternion");

ATTRIBUTE_HELPER_CPP (Quaternion);

Quaternion::Quaternion (double _x, double _y, double _z, double _w)
  : x (_x),
    y (_y),
    z (_z),
    w (_w)
{
  NS_LOG_FUNCTION (this << _x << _y << _z << _w);
}

Quaternion::Quaternion ()
  : x (0.0),
    y (0.0),
    z (0.0),
    w (1.0)
{
  NS_LOG_FUNCTION (this);
}

double
Quaternion::GetLength () const
{
  NS_LOG_FUNCTION (this);
  return std::sqrt (x * x + y * y + z * z + w * w);
}

std::ostream &operator << (std::ostream &os, const Quaternion &Quaternion)
{
  os << Quaternion.x << ":" << Quaternion.y << ":" << Quaternion.z << ":" << Quaternion.w;
  return os;
}
std::istream &operator >> (std::istream &is, Quaternion &Quaternion)
{
  char c1, c2, c3;
  is >> Quaternion.x >> c1 >> Quaternion.y >> c2 >> Quaternion.z >> c3 >> Quaternion.w;
  if (c1 != ':'
      || c2 != ':'
      || c3 != ':')
    {
      is.setstate (std::ios_base::failbit);
    }
  return is;
}

bool operator == (const Quaternion &a, const Quaternion &b)
{
  return std::tie (a.x, a.y, a.z, a.w) ==
         std::tie (b.x, b.y, b.z, b.w);
}
bool operator != (const Quaternion &a, const Quaternion &b)
{
  return !(a == b);
}

Quaternion
operator * (const Quaternion &a, const Quaternion &b)
{
  return Quaternion (a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y,
                     a.w * b.y + a.y * b.w + a.z * b.x - a.x * b.z,
                     a.w * b.z + a.z * b.w + a.x * b.y - a.y * b.x,
                     a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z);
}

Quaternion
operator + (const Quaternion &a, const Quaternion &b)
{
  return Quaternion (a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

Quaternion
operator - (const Quaternion &a, const Quaternion &b)
{
  return Quaternion (a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

} // namespace ns3
