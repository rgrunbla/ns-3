/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2009 University of Washington
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
 * Author
 */

// An essential include is test.h
#include "ns3/test.h"

/**
 * \file
 * \ingroup core-tests
 * \ingroup testing
 * \ingroup testing-example
 * Quaternion test suite.
 */

/**
 * \ingroup core-tests
 * \defgroup testing-example Example use of TestSuite
 */

namespace ns3 {

namespace tests {


/**
 * \ingroup testing-example
 * This is an example TestCase.
 */
class QuaternionTestCase1 : public TestCase
{
public:
  /** Constructor. */
  QuaternionTestCase1 ();
  /** Destructor. */
  virtual ~QuaternionTestCase1 ();

private:
  virtual void DoRun (void);
};

/** Add some help text to this case to describe what it is intended to test. */
QuaternionTestCase1::QuaternionTestCase1 ()
  : TestCase ("Sample test case (does nothing)")
{}

/**
 * This destructor does nothing but we include it as a reminder that
 * the test case should clean up after itself
 */
QuaternionTestCase1::~QuaternionTestCase1 ()
{}

/**
 * This method is the pure virtual method from class TestCase that every
 * TestCase must implement
 */
void
QuaternionTestCase1::DoRun (void)
{
  // A wide variety of test macros are available in src/core/test.h
  NS_TEST_ASSERT_MSG_EQ (true, true, "true doesn't equal true for some reason");
  // Use this one for floating point comparisons
  NS_TEST_ASSERT_MSG_EQ_TOL (0.01, 0.01, 0.001, "Numbers are not equal within tolerance");
}

/**
 * \ingroup testing-example
 * The TestSuite class names the TestSuite, identifies what type of TestSuite,
 * and enables the TestCases to be run.  Typically, only the constructor for
 * this class must be defined
 */
class QuaternionTestSuite : public TestSuite
{
public:
  /** Constructor. */
  QuaternionTestSuite ();
};

QuaternionTestSuite::QuaternionTestSuite ()
  : TestSuite ("quaternion")
{
  AddTestCase (new QuaternionTestCase1);
}

// Do not forget to allocate an instance of this TestSuite
/**
 * \ingroup testing-example
 * QuaternionTestSuite instance variable.
 */
static QuaternionTestSuite g_sampleTestSuite;


}    // namespace tests

}  // namespace ns3
