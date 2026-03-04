using EmbedIO;
using EmbedIO.Actions;
using EmbedIO.WebApi;
using System.Text;

namespace RoboDeviceEmulator
{
    public partial class Form1 : Form
    {
        private WebServer _webServer;

        public Form1()
        {
            InitializeComponent();
        }

        private async void Form1_Load(object sender, EventArgs e)
        {
            // Создаём сервер на порту 8080 (только локальный доступ)
            _webServer = new WebServer(o => o
                    .WithUrlPrefix("http://localhost:9696")
                    .WithMode(HttpListenerMode.EmbedIO))
                    .WithLocalSessionManager()
                    .WithWebApi("/api", m => m.WithController<ApiController>())
                    .WithAction("/index", HttpVerbs.Any, ctx => ctx.SendDataAsync(new { message = "Hola mundo" }))
                    .WithAction("/RHL/v0-1/status", HttpVerbs.Any, ctx => ctx.SendDataAsync(new { status = "OK" }))
                    .WithAction("/", HttpVerbs.Any, ctx => ctx.SendDataAsync(new { status = "Error" }));


            // Запускаем сервер в фоновом потоке
            await _webServer.RunAsync();
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            _webServer?.Dispose();
        }
    }
}
