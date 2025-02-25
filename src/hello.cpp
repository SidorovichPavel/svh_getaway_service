#include "hello.hpp"

#include <fmt/format.h>

#include <userver/server/handlers/http_handler_base.hpp>

namespace svh_gateway_service {

namespace {

class Hello final : public userver::server::handlers::HttpHandlerBase {
public:
  static constexpr std::string_view kName = "handler-hello";

  using HttpHandlerBase::HttpHandlerBase;

  std::string HandleRequestThrow(
      const userver::server::http::HttpRequest &request,
      userver::server::request::RequestContext &) const override {
    return svh_gateway_service::SayHelloTo(request.GetArg("name"));
  }
};

} // namespace

std::string SayHelloTo(std::string_view name) {
  if (name.empty()) {
    name = "unknown user";
  }

  return fmt::format("Hello, {}!\n", name);
}

void AppendHello(userver::components::ComponentList &component_list) {
  component_list.Append<Hello>();
}

} // namespace svh_gateway_service
