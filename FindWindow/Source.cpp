#include <iostream> // Input/output
#include <tchar.h> // TCHAR data type.
#include <Windows.h> // Common windows functions.
#include <Psapi.h> // GetModuleFileNameEx
//#include <Shlwapi.h>
//#include <string>


using namespace std;



/*std::string ProcessName(DWORD ProcessId)
{
	std::string name;
	HANDLE Handle = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, ProcessId);

	if (Handle){

		TCHAR Buffer[MAX_PATH];
		

		if (GetModuleFileNameEx(Handle, 0, Buffer, MAX_PATH)){
			//name = std::string(PathFindFileName(Buffer));
			
		}
		else
		{
			// GetLastError().
		}
		CloseHandle(Handle);
	}

	return name;



}*/







int main(){


	HWND WindowHandle = FindWindowA(NULL, "Sticky Notes");
	DWORD pID = -1;
	GetWindowThreadProcessId(WindowHandle, &pID);


	if (WindowHandle){

		cout << "Window found." << endl;
		cout << "Process ID: " << pID << endl;

	}
	else{

		cout << "The window was not found!?" << endl;
	}

	// Now open the process

	HANDLE hProc = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, false, pID);
	//HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, false, pID);


	if (hProc){

		cout << "Succesfully opened process." << endl;

		TCHAR Buffer[MAX_PATH];
		
		std::string name;


		GetProcessImageFileName(hProc, Buffer, MAX_PATH); // Returns full path on HDD.
		//GetModuleFileNameEx(hProc, NULL, Buffer, MAX_PATH); // Should return Exe path, returns garbage.
		//GetModuleFileName(NULL, Buffer, MAX_PATH);
		
		cout << "Base module: " << Buffer << endl;
		cout << "Error(if any): " << GetLastError() << endl;

	

	}
	else
	{

		cout << "Could not open process!" << endl;
		cout << "Error: " << GetLastError() << endl;

	}
	
	CloseHandle(hProc); // Close handle after we're done.


	Sleep(25000);

	return 0;

}