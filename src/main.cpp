#include "player.h"

#include <windows.h>

#include <iostream>
#include <string>

int main() {
	try {
		const auto process = win::mem::Process::open(win::mem::Process::AccessRights::ALL_ACCESS, FALSE, "hl2.exe");

		const auto clientBase = process.getModuleBase("client.dll");
		const auto engineBase = process.getModuleBase("engine.dll");
		const auto serverBase = process.getModuleBase("server.dll");

		std::cout << (void*)clientBase << '\n' << (void*)engineBase << '\n' << (void*)serverBase << '\n';
	} catch (std::out_of_range e) {
		std::cout << (std::string(e.what())) << '\n';
	}

	/*const auto sleepDuration = 3000;
	const auto key = VK_END;

	const int baseAddress = 0x0B72674C;
	const LPCVOID pBaseAddress = reinterpret_cast<LPCVOID>(baseAddress);
	int crosshairId;

	INPUT input;

	input.type = INPUT_MOUSE;
	input.mi.dx = (LONG)(GetSystemMetrics(SM_CXSCREEN) / 2.0 * (65536.0 / GetSystemMetrics(SM_CXSCREEN)));
	input.mi.dy = (LONG)(GetSystemMetrics(SM_CYSCREEN) / 2.0 * (65536.0 / GetSystemMetrics(SM_CYSCREEN)));
	input.mi.mouseData = 0x0001;
	input.mi.time = 0;

	for (int i = 0; !GetAsyncKeyState(key);) {
	process.read(pBaseAddress, &crosshairId, sizeof(crosshairId));

	if (crosshairId > 0 && crosshairId <= 62) {
	input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN;

	SendInput(1, &input, sizeof(input));

	input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTUP;

	SendInput(1, &input, sizeof(input));

	std::cout << "FIRE " << i++ << '\n';
	}
	}*/
}
