#include <WinReg.hpp>
#include <Windows.h>
#include <iostream>
#include <termcolor.hpp>
using namespace std;

namespace CEBypass {
	void Bypass() {
		CreateDirectoryW((LPCWSTR)L"C:\\CEBypass", NULL);
		SetFileAttributesW((LPCWSTR)L"C:\\CEBypass", FILE_ATTRIBUTE_HIDDEN);
		winreg::RegKey key{ HKEY_CURRENT_USER, L"Software\\Cheat Engine", KEY_ALL_ACCESS };
		if (!key) {
			cout << termcolor::color<120, 0, 0> << "FAILED!!!" << endl;
			MessageBoxA(0, "Please Download Cheat Engine, Run Cheat Engine, Skip CE Tutorial, Quit from CE(Cheat Engine), Run This Bypass Again and Again Run CE(Cheat Engine)!!!", "CEBypass by RikkoMatsumato", 0);
			exit(122);
		}
		else {
			key.DeleteValue(L"Don't use tempdir");
			key.SetDwordValue(L"Don't use tempdir", (DWORD)1);
			key.DeleteValue(L"Scanfolder");
			key.SetStringValue(L"Scanfolder", L"C:\\CEBypass\\");
			cout << termcolor::color<120, 45, 45> << "SUCCESSFULLY BYPASSED!!! \nCREATED BY RikkoMatsumato" << endl;
			exit(344);
		}
	}
}

int main()
{
	CEBypass::Bypass();
	return 0;
}
