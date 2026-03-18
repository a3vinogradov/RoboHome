namespace RoboDeviceEmulator
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        private Button createEmulatorButton;
        private DataGridView emulatorsDataGridView;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            emulatorsDataGridView = new DataGridView();
            grdColumnName = new DataGridViewTextBoxColumn();
            grdColumnUrl = new DataGridViewTextBoxColumn();
            grdColumnStatus = new DataGridViewTextBoxColumn();
            grdColumnSwitch = new DataGridViewButtonColumn();
            grdColumnDelete = new DataGridViewButtonColumn();
            createEmulatorButton = new Button();
            btnUpdate = new Button();
            menuStrip1 = new MenuStrip();
            toolStrip1 = new ToolStrip();
            fileToolStripMenuItem = new ToolStripMenuItem();
            saveConfigurationToolStripMenuItem = new ToolStripMenuItem();
            loadConfigurationToolStripMenuItem = new ToolStripMenuItem();
            ((System.ComponentModel.ISupportInitialize)emulatorsDataGridView).BeginInit();
            menuStrip1.SuspendLayout();
            SuspendLayout();
            // 
            // emulatorsDataGridView
            // 
            emulatorsDataGridView.AllowUserToAddRows = false;
            emulatorsDataGridView.AllowUserToDeleteRows = false;
            emulatorsDataGridView.Anchor = AnchorStyles.Top | AnchorStyles.Bottom | AnchorStyles.Left | AnchorStyles.Right;
            emulatorsDataGridView.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
            emulatorsDataGridView.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            emulatorsDataGridView.Columns.AddRange(new DataGridViewColumn[] { grdColumnName, grdColumnUrl, grdColumnStatus, grdColumnSwitch, grdColumnDelete });
            emulatorsDataGridView.Location = new Point(12, 117);
            emulatorsDataGridView.Name = "emulatorsDataGridView";
            emulatorsDataGridView.Size = new Size(1002, 423);
            emulatorsDataGridView.TabIndex = 0;
            emulatorsDataGridView.CellContentClick += emulatorsDataGridView_CellContentClick;
            // 
            // grdColumnName
            // 
            grdColumnName.HeaderText = "Наименование";
            grdColumnName.Name = "grdColumnName";
            // 
            // grdColumnUrl
            // 
            grdColumnUrl.HeaderText = "Url";
            grdColumnUrl.Name = "grdColumnUrl";
            // 
            // grdColumnStatus
            // 
            grdColumnStatus.HeaderText = "Состояние";
            grdColumnStatus.Name = "grdColumnStatus";
            // 
            // grdColumnSwitch
            // 
            grdColumnSwitch.HeaderText = "";
            grdColumnSwitch.Name = "grdColumnSwitch";
            // 
            // grdColumnDelete
            // 
            grdColumnDelete.HeaderText = "";
            grdColumnDelete.Name = "grdColumnDelete";
            // 
            // createEmulatorButton
            // 
            createEmulatorButton.Location = new Point(12, 88);
            createEmulatorButton.Name = "createEmulatorButton";
            createEmulatorButton.Size = new Size(150, 23);
            createEmulatorButton.TabIndex = 1;
            createEmulatorButton.Text = "Create Emulator";
            createEmulatorButton.UseVisualStyleBackColor = true;
            createEmulatorButton.Click += CreateEmulatorButton_Click;
            // 
            // btnUpdate
            // 
            btnUpdate.Location = new Point(171, 88);
            btnUpdate.Name = "btnUpdate";
            btnUpdate.Size = new Size(139, 23);
            btnUpdate.TabIndex = 2;
            btnUpdate.Text = "Обновить";
            btnUpdate.UseVisualStyleBackColor = true;
            btnUpdate.Click += btnUpdate_Click;
            // 
            // menuStrip1
            // 
            menuStrip1.Items.AddRange(new ToolStripItem[] { fileToolStripMenuItem });
            menuStrip1.Location = new Point(0, 0);
            menuStrip1.Name = "menuStrip1";
            menuStrip1.Size = new Size(1026, 24);
            menuStrip1.TabIndex = 3;
            menuStrip1.Text = "menuStrip1";
            // 
            // toolStrip1
            // 
            toolStrip1.Location = new Point(0, 24);
            toolStrip1.Name = "toolStrip1";
            toolStrip1.Size = new Size(1026, 25);
            toolStrip1.TabIndex = 4;
            toolStrip1.Text = "toolStrip1";
            // 
            // fileToolStripMenuItem
            // 
            fileToolStripMenuItem.DropDownItems.AddRange(new ToolStripItem[] { saveConfigurationToolStripMenuItem, loadConfigurationToolStripMenuItem });
            fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            fileToolStripMenuItem.Size = new Size(37, 20);
            fileToolStripMenuItem.Text = "File";
            // 
            // saveConfigurationToolStripMenuItem
            // 
            saveConfigurationToolStripMenuItem.Name = "saveConfigurationToolStripMenuItem";
            saveConfigurationToolStripMenuItem.Size = new Size(180, 22);
            saveConfigurationToolStripMenuItem.Text = "Save configuration";
            saveConfigurationToolStripMenuItem.Click += saveConfigurationToolStripMenuItem_Click;
            // 
            // loadConfigurationToolStripMenuItem
            // 
            loadConfigurationToolStripMenuItem.Name = "loadConfigurationToolStripMenuItem";
            loadConfigurationToolStripMenuItem.Size = new Size(180, 22);
            loadConfigurationToolStripMenuItem.Text = "Load configuration";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1026, 552);
            Controls.Add(toolStrip1);
            Controls.Add(btnUpdate);
            Controls.Add(emulatorsDataGridView);
            Controls.Add(createEmulatorButton);
            Controls.Add(menuStrip1);
            MainMenuStrip = menuStrip1;
            Name = "Form1";
            Text = "IoT Emulators";
            FormClosing += Form1_FormClosing;
            ((System.ComponentModel.ISupportInitialize)emulatorsDataGridView).EndInit();
            menuStrip1.ResumeLayout(false);
            menuStrip1.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion
        private Button btnUpdate;
        private DataGridViewTextBoxColumn grdColumnName;
        private DataGridViewTextBoxColumn grdColumnUrl;
        private DataGridViewTextBoxColumn grdColumnStatus;
        private DataGridViewButtonColumn grdColumnSwitch;
        private DataGridViewButtonColumn grdColumnDelete;
        private MenuStrip menuStrip1;
        private ToolStrip toolStrip1;
        private ToolStripMenuItem fileToolStripMenuItem;
        private ToolStripMenuItem saveConfigurationToolStripMenuItem;
        private ToolStripMenuItem loadConfigurationToolStripMenuItem;
    }
}
