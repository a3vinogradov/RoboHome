using EmbedIO.Routing;
using EmbedIO;
using EmbedIO.WebApi;

namespace RoboDeviceEmulator
{
    internal class ApiController : WebApiController
    {
        [Route(HttpVerbs.Get, "/status")]
        public object GetGreeting() => new {status = "OK", T1=1245};
    }
}
