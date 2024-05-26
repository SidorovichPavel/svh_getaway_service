#pragma once

#include <string>
#include <string_view>

#include <userver/components/component_list.hpp>

namespace svh_gateway_service {

std::string SayHelloTo(std::string_view name);

void AppendHello(userver::components::ComponentList &component_list);

} // namespace svh_gateway_service
