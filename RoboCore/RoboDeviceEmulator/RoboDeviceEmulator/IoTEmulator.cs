using EmbedIO;
using EmbedIO.Actions;
using EmbedIO.WebApi;
using System;
using System.Threading.Tasks;

namespace RoboDeviceEmulator
{
    public class IoTEmulator
    {
        private WebServer _webServer;
        public string Name { get; private set; }
        public string Url { get; private set; }
        //public bool IsRunning {


        //}

        public IoTEmulator(string name, string url)
        {
            Name = name;
            Url = url;
        }

        //public void Start()
        //{
        //    _webServer ??= new WebServer(o => o
        //                    .WithUrlPrefix(Url)
        //                    .WithMode(HttpListenerMode.EmbedIO)
        //                    )
        //                .WithLocalSessionManager()
        //                .WithAction("/RHL/v0-1/status", HttpVerbs.Any, ctx => ctx.SendDataAsync(new { status = "OK" }));

        //    if ((_webServer.State == WebServerState.Created) ||
        //        (_webServer.State == WebServerState.Stopped))
        //    {
        //        _webServer.Start();
        //    }
        //}

        //public async Task StopAsync()
        //{
        //    if (!IsRunning) return;
        //    _webServer.Dispose();
        //    IsRunning = false;
        //}
    }
}