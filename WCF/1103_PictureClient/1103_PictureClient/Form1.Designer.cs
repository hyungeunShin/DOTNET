
namespace _1103_PictureClient
{
    partial class Form1
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.파일ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.그림목록보기VToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.그림업로드하기UToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.파일ToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(800, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // 파일ToolStripMenuItem
            // 
            this.파일ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.그림목록보기VToolStripMenuItem,
            this.그림업로드하기UToolStripMenuItem});
            this.파일ToolStripMenuItem.Name = "파일ToolStripMenuItem";
            this.파일ToolStripMenuItem.Size = new System.Drawing.Size(51, 20);
            this.파일ToolStripMenuItem.Text = "파일(&)";
            // 
            // 그림목록보기VToolStripMenuItem
            // 
            this.그림목록보기VToolStripMenuItem.Name = "그림목록보기VToolStripMenuItem";
            this.그림목록보기VToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.그림목록보기VToolStripMenuItem.Text = "그림목록보기(&V)";
            this.그림목록보기VToolStripMenuItem.Click += new System.EventHandler(this.그림목록보기VToolStripMenuItem_Click);
            // 
            // 그림업로드하기UToolStripMenuItem
            // 
            this.그림업로드하기UToolStripMenuItem.Name = "그림업로드하기UToolStripMenuItem";
            this.그림업로드하기UToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.그림업로드하기UToolStripMenuItem.Text = "그림업로드하기(&U)";
            this.그림업로드하기UToolStripMenuItem.Click += new System.EventHandler(this.그림업로드하기UToolStripMenuItem_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.menuStrip1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MainMenuStrip = this.menuStrip1;
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.Text = "PictureClient";
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.Form1_Paint);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem 파일ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 그림목록보기VToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 그림업로드하기UToolStripMenuItem;
    }
}

