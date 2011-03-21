#pragma once


namespace VisualTimer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
		// variable declarations 
	private: bool bSettingMode;
	private: bool bDisplaySweepHand;
	private: bool bDisplayDigitalTimer;
	private: Point dialCenter;
	private: int dialAngle; // default to the twelve o'clock position
	private: float sweepHandAngle;

	private: Color dialColor;
	private: DateTime dtStartTime;
	private: System::Windows::Forms::Button^  button1;
	private: DateTime dtCurrentTime;

	private: double fScaleFactor;
	private: double fSecondScale;
	private: double fMinuteScale;
	private: double fHourScale;

	private: int majorTickLength;
	private: int minorTickLength;
	private: int dialRadius;

	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			fSecondScale = 6.0;
			fMinuteScale = 0.1;
			fHourScale = 0.00833;

			bSettingMode = false; // initially we don't want to be in setting mode.
			dialAngle = 0;
			dialCenter.X = tabPage1->Width/2;
			dialCenter.Y = tabPage1->Height/2;
			dialRadius = Math::Min(dialCenter.X, dialCenter.Y);
			majorTickLength = 10;
			minorTickLength = 5;
			dialColor = Color::Red;
		}
	public:
		void ToggleSettingMode(void)
		{
			bSettingMode = !bSettingMode;
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  unitsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  hoursToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  minutesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  secondsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Timer^  tickTimer;
	private: System::Diagnostics::Process^  process1;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->unitsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->hoursToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->minutesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->secondsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->tickTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->process1 = (gcnew System::Diagnostics::Process());
			this->menuStrip1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->unitsToolStripMenuItem, 
				this->helpToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(464, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// unitsToolStripMenuItem
			// 
			this->unitsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->hoursToolStripMenuItem, 
				this->minutesToolStripMenuItem, this->secondsToolStripMenuItem});
			this->unitsToolStripMenuItem->Name = L"unitsToolStripMenuItem";
			this->unitsToolStripMenuItem->Size = System::Drawing::Size(46, 20);
			this->unitsToolStripMenuItem->Text = L"Units";
			// 
			// hoursToolStripMenuItem
			// 
			this->hoursToolStripMenuItem->Name = L"hoursToolStripMenuItem";
			this->hoursToolStripMenuItem->Size = System::Drawing::Size(118, 22);
			this->hoursToolStripMenuItem->Text = L"Hours";
			this->hoursToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::hoursToolStripMenuItem_Click);
			// 
			// minutesToolStripMenuItem
			// 
			this->minutesToolStripMenuItem->Checked = true;
			this->minutesToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->minutesToolStripMenuItem->Name = L"minutesToolStripMenuItem";
			this->minutesToolStripMenuItem->Size = System::Drawing::Size(118, 22);
			this->minutesToolStripMenuItem->Text = L"Minutes";
			this->minutesToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::minutesToolStripMenuItem_Click);
			// 
			// secondsToolStripMenuItem
			// 
			this->secondsToolStripMenuItem->Name = L"secondsToolStripMenuItem";
			this->secondsToolStripMenuItem->Size = System::Drawing::Size(118, 22);
			this->secondsToolStripMenuItem->Text = L"Seconds";
			this->secondsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::secondsToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->aboutToolStripMenuItem});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::aboutToolStripMenuItem_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(12, 27);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(440, 395);
			this->tabControl1->TabIndex = 1;
			// 
			// tabPage1
			// 
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(432, 369);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Timer";
			this->tabPage1->UseVisualStyleBackColor = true;
			this->tabPage1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::tabPage1_Paint);
			this->tabPage1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::tabPage1_MouseMove);
			this->tabPage1->Click += gcnew System::EventHandler(this, &Form1::tabPage1_Click);
			this->tabPage1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::tabPage1_MouseClick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(377, 424);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(432, 388);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Settings";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// tickTimer
			// 
			this->tickTimer->Interval = 1000;
			this->tickTimer->Tick += gcnew System::EventHandler(this, &Form1::tickTimer_Tick);
			// 
			// process1
			// 
			this->process1->StartInfo->Domain = L"";
			this->process1->StartInfo->LoadUserProfile = false;
			this->process1->StartInfo->Password = nullptr;
			this->process1->StartInfo->StandardErrorEncoding = nullptr;
			this->process1->StartInfo->StandardOutputEncoding = nullptr;
			this->process1->StartInfo->UserName = L"";
			this->process1->SynchronizingObject = this;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(464, 453);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->menuStrip1);
			this->DoubleBuffered = true;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"VisualTimer";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void hoursToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 minutesToolStripMenuItem->Checked = false;
			 hoursToolStripMenuItem->Checked = true;
			 secondsToolStripMenuItem->Checked = false;
			 dialColor = Color::Blue;
			 tabPage1->Invalidate();
			 fScaleFactor = fHourScale;
		 }
private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			
		 }
private: System::Void minutesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 minutesToolStripMenuItem->Checked = true;
			 hoursToolStripMenuItem->Checked = false;
			 secondsToolStripMenuItem->Checked = false;
			 dialColor = Color::Red;
			 fScaleFactor = fMinuteScale;
			 tabPage1->Invalidate();
		 }
private: System::Void secondsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 minutesToolStripMenuItem->Checked = false;
			 hoursToolStripMenuItem->Checked = false;
			 secondsToolStripMenuItem->Checked = true;
			 dialColor = Color::Green;
			 fScaleFactor = fSecondScale;
			 tabPage1->Invalidate();
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {

		 }
private: System::Void tabPage1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			// draw the timer window
			//TODO:
			 // (1) Numbers around the perimeter
			 // (2) Tick marks 
			 // (3) set the start and sweep angles during mouse movment 
			 // (4) draw an optional second hand.

			// declare a pen
			Pen^ paintPen = gcnew Pen( System::Drawing::Brushes::Black);
			paintPen->Width = 1.0F;
			SolidBrush^ paintBrush;

			if (this->bSettingMode == false) {
				paintBrush = gcnew SolidBrush(dialColor);
			} else {
				paintBrush = gcnew SolidBrush(Color::Black);
			}
			// draw the tick marks.
			// First check the minutes/seconds/hours menu
			// then do this:
			// for now assume minutes/seconds settings (12 tick marks)
			int increment = 6;
			for(int i=-90; i<270; i+=6)
			{
				float x1=(float) dialRadius * Math::Sin(i * (Math::PI/180))+ dialCenter.X - (3*majorTickLength)-1;
				float y1=(float) dialRadius * Math::Cos(i * (Math::PI/180)) + dialCenter.Y;
				float x2=(float) (dialRadius-majorTickLength) * Math::Sin(i * (Math::PI/180)) + dialCenter.X - (3*majorTickLength)-1;
				float y2=(float) (dialRadius-majorTickLength) * Math::Cos(i * (Math::PI/180)) + dialCenter.Y;

				e->Graphics->DrawLine(paintPen, x1, y1, x2, y2);
			}

			 // declare a rectangle to draw the indicator dial (wheel)
			Rectangle paintRect = Rectangle(0,0,Math::Min(tabPage1->Width,tabPage1->Height),Math::Min(tabPage1->Width,tabPage1->Height));
			e->Graphics->DrawEllipse(paintPen, paintRect);
			e->Graphics->FillPie(paintBrush, paintRect, -90, dialAngle);
		 }

private: System::Void tabPage1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 this->ToggleSettingMode();
			 tabPage1->Invalidate();
		 }
private: System::Void tickTimer_Tick(System::Object^  sender, System::EventArgs^  e) {
			 // TODO:
			 // add everything that happens on each timer tick.
			 // (1) adjust the angle for the sweep hand if we're using it.
			 // (2) adjust the angle for the setting wheel.
			 // (3) adjust the timer variable
			 // (4) update the digital timer display if it's on.
			 // (5) force a redraw of the display.

			 tabPage1->Invalidate();
		 }
private: System::Void tabPage1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 // Check if we are in setting mode. If so, update the angle variable for the 
			 // setting wheel and invalidate. 
			 if (bSettingMode == true)
			 {
				 // calculations
				 Point mouseXY = e->Location;
				 
				 // convert the mouse position into a sweep angle for Fill Pie.
				 // correct for negative angles, and restrict to whole-unit intervals.

				 dialAngle = Convert::ToInt32((Math::Atan2(mouseXY.Y - dialCenter.Y, mouseXY.X-dialCenter.X) * (180/Math::PI)) + 90);
				 if (dialAngle < 0) {
					 dialAngle += 360;
				 }
				 int angMod;
				 angMod = dialAngle % 6;
				 if (angMod > 0 && angMod < 4) {
					 dialAngle -= angMod;
				 } else if (angMod >=4) {
					 dialAngle += (6-angMod);
				 }

				 // using the dial center value and the mouseXY variable, calculate the angle from straight up (-90 
				 // in the GDI's coordinates
				 // force a repaint
				 tabPage1->Invalidate();
			 }
		 }
private: System::Void tabPage1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

