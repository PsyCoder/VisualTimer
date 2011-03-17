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
	private: bool bSettingMode;
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			bSettingMode = false; // initially we don't want to be in setting mode.
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
			this->tabControl1->Size = System::Drawing::Size(440, 403);
			this->tabControl1->TabIndex = 1;
			// 
			// tabPage1
			// 
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(432, 377);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Timer";
			this->tabPage1->UseVisualStyleBackColor = true;
			this->tabPage1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::tabPage1_Paint);
			this->tabPage1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::tabPage1_MouseClick);
			// 
			// tabPage2
			// 
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(432, 377);
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
			this->ClientSize = System::Drawing::Size(464, 442);
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
		 }
private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			
		 }
private: System::Void minutesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 minutesToolStripMenuItem->Checked = true;
			 hoursToolStripMenuItem->Checked = false;
			 secondsToolStripMenuItem->Checked = false;
		 }
private: System::Void secondsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 minutesToolStripMenuItem->Checked = false;
			 hoursToolStripMenuItem->Checked = false;
			 secondsToolStripMenuItem->Checked = true;
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
			Pen^ paintPen = gcnew Pen( System::Drawing::Brushes::Red);
			paintPen->Width = 1.0F;
			SolidBrush^ paintBrush;
			if (this->bSettingMode == false) {
				paintBrush = gcnew SolidBrush(Color::Red);
			} else {
				paintBrush = gcnew SolidBrush(Color::Black);
			}
			 // declare a rectangle
			Rectangle paintRect = Rectangle(0,0,Math::Min(tabPage1->Width,tabPage1->Height),Math::Min(tabPage1->Width,tabPage1->Height));
		
			 e->Graphics->FillPie(paintBrush, paintRect, 0, 90);
		 }

private: System::Void tabPage1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 this->ToggleSettingMode();
			 tabPage1->Invalidate();
		 }
private: System::Void tickTimer_Tick(System::Object^  sender, System::EventArgs^  e) {
			 // TODO:
			 // add everything that happens on each timer tick.
		 }
};
}

