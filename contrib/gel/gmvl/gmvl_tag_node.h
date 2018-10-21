// This is gel/gmvl/gmvl_tag_node.h
#ifndef gmvl_tag_node_h_
#define gmvl_tag_node_h_
//:
// \file
// \author crossge@crd.ge.com
//
// \verbatim
//  Modifications
//   10 Sep. 2004 Peter Vanroose  Inlined all 1-line methods in class decl
// \endverbatim

#include <gmvl/gmvl_node.h>
#include <iostream>
#include <string>
#include <utility>
#include <vcl_compiler.h>

class gmvl_tag_node : public gmvl_node
{
 public:
  gmvl_tag_node(std::string  name) : name_(std::move(name)) { type_="gmvl_tag_node"; }
  ~gmvl_tag_node() = default;

  // accessor
  std::string &get() { return name_; }

 protected:
  std::string name_;
};

#endif // gmvl_tag_node_h_
