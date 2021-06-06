#pragma once

namespace MyNovelList {

	ref class DB_Panel : public System::Windows::Forms::Panel
	{
	public:
		DB_Panel()
		{
			this->DoubleBuffered = true;
		}
	};

}