using EmbedIO;
using EmbedIO.Actions;
using EmbedIO.WebApi;
using System;
using System.Collections.Generic;
using System.Threading.Tasks;

namespace RoboDeviceEmulator
{
    public partial class Form1 : Form
    {
        private List<IoTEmulator> _emulators;
        private int _nextPort;

        public Form1()
        {
            InitializeComponent();
            _emulators = new List<IoTEmulator>();
            _nextPort = 9696;
        }

        // Form1_Load удалён, так как логика перенесена в OnLoad

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            foreach (var emulator in _emulators)
            {
                //if (emulator.IsRunning)
                //{
                //    emulator.StopAsync().Wait();
                //}
            }
        }
        private void CreateEmulatorButton_Click(object sender, EventArgs e)
        {
            string name = $"Emulator_{_emulators.Count + 1}";
            string url = $"http://localhost:{_nextPort++}";
            var emulator = new IoTEmulator(name, url);
            _emulators.Add(emulator);
            UpdateEmulatorsGrid();
            //_ = emulator.StartAsync();
        }

        private void UpdateEmulatorsGrid()
        {
            emulatorsDataGridView.Rows.Clear();
            foreach (var emulator in _emulators)
            {
                var row = new DataGridViewRow();
                row.CreateCells(emulatorsDataGridView);
                row.Cells[0].Value = emulator.Name;
                row.Cells[1].Value = emulator.Url;
                row.Cells[1].Tag = emulator.Url;
                row.Cells[2].Value = false;
                row.Cells[3].Value = "Start";
                row.Cells[4].Value = "Удалить";
                row.Tag = emulator;
                emulatorsDataGridView.Rows.Add(row);
            }
        }

        protected override void OnLoad(EventArgs e)
        {
            base.OnLoad(e);
            UpdateEmulatorsGrid();
        }

        private void emulatorsDataGridView_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

            if (e.ColumnIndex == emulatorsDataGridView.Columns["Stop"]?.Index)
            {
                var row = emulatorsDataGridView.Rows[e.RowIndex];
                var emulator = row.Tag as IoTEmulator;
                if (emulator != null)
                {
                    //_ = emulator.StopAsync();
                    UpdateEmulatorsGrid();
                }
            }
            else if (e.ColumnIndex == emulatorsDataGridView.Columns["Url"]?.Index)
            {
                var cell = emulatorsDataGridView.Rows[e.RowIndex].Cells["Url"];
                var url = cell.Tag as string;
                if (!string.IsNullOrEmpty(url))
                {
                    System.Diagnostics.Process.Start(new System.Diagnostics.ProcessStartInfo(url) { UseShellExecute = true });
                }
            }
            else if (e.ColumnIndex == grdColumnDelete.Index)
            {
                MessageBox.Show("Кнопка Удалить нажата");
            }
        }

        private void btnUpdate_Click(object sender, EventArgs e)
        {
            UpdateEmulatorsGrid();
        }

        private void saveConfigurationToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }
    }
}
