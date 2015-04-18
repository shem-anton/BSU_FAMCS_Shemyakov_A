#undef UNICODE
#include <windows.h>
#include <fstream>
#include <vector>
#include <string>
#include "resource.h"
//SHOW_WINDOW, HIDE_WINDOW
INT_PTR CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

struct question
{
	std::string text; 
	std::string answers[5];
	int correct_answer;//, users_answer;
};

static std::vector<question> questions;
static int num = 0;
static HWND hEdit, HEdit, hQ, hRadio1, hRadio2, hRadio3, hRadio4;
HINSTANCE hinst;
static HWND HDLG;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE, LPTSTR, int)
{
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
	hinst = hInstance;
	return 0;
}

INT_PTR CALLBACK DlgProc1(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
		{
			HEdit = GetDlgItem(hDlg, IDC_EDIT1);
			hRadio1 = GetDlgItem(hDlg, IDC_RADIO1);
			hRadio2 = GetDlgItem(hDlg, IDC_RADIO2);
			hRadio3 = GetDlgItem(hDlg, IDC_RADIO3);
			hRadio4 = GetDlgItem(hDlg, IDC_RADIO4);
			SetWindowText(HEdit, "Enter the number of question");
		}
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		if(LOWORD(wParam) == IDOK)
		{
			char buf[10];
			GetWindowText(HEdit, buf, -1);
			num = atoi(buf);
			num--;
			SetWindowText(hEdit, questions[num].text.c_str());
			SetWindowText(hEdit, questions[num].text.c_str());
			hQ = GetDlgItem(HDLG, IDC_RADIO1);
			SetWindowText(hQ, questions[num].answers[1].c_str());
			hQ = GetDlgItem(HDLG, IDC_RADIO2);
			SetWindowText(hQ, questions[num].answers[2].c_str());
			hQ = GetDlgItem(HDLG, IDC_RADIO3);
			SetWindowText(hQ, questions[num].answers[3].c_str());
			hQ = GetDlgItem(HDLG, IDC_RADIO4);
			SetWindowText(hQ, questions[num].answers[4].c_str());
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}


INT_PTR CALLBACK DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
		{
			HDLG = hDlg;
			hEdit = GetDlgItem(hDlg, IDC_EDIT1);
			std::ifstream fin("input.txt");
			while(!fin.eof())
			{
				std::string buf, t;
				//int i;
				question temp;
				std::getline(fin,temp.text);
				//std::getline(fin, buf);
				//i = atoi(buf.c_str());
				for(int j = 0; j < 4; ++j)
				{
					std::getline(fin, t);
					temp.answers[j+1] = t;
				}
				std::getline(fin, buf);
				temp.correct_answer = atoi(buf.c_str());
				questions.push_back(temp);
			}

		}
		SetWindowText(hEdit, questions[num].text.c_str());
		hQ = GetDlgItem(hDlg, IDC_RADIO1);
		SetWindowText(hQ, questions[num].answers[1].c_str());
		hQ = GetDlgItem(hDlg, IDC_RADIO2);
		SetWindowText(hQ, questions[num].answers[2].c_str());
		hQ = GetDlgItem(hDlg, IDC_RADIO3);
		SetWindowText(hQ, questions[num].answers[3].c_str());
		hQ = GetDlgItem(hDlg, IDC_RADIO4);
		SetWindowText(hQ, questions[num].answers[4].c_str());
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		if(LOWORD(wParam) == IDC_BUTTON1)
			if(num<questions.size() - 1)
			{
				num++;
				SetWindowText(hEdit, questions[num].text.c_str());
			SetWindowText(hEdit, questions[num].text.c_str());
			hQ = GetDlgItem(hDlg, IDC_RADIO1);
			SetWindowText(hQ, questions[num].answers[1].c_str());
			hQ = GetDlgItem(hDlg, IDC_RADIO2);
			SetWindowText(hQ, questions[num].answers[2].c_str());
			hQ = GetDlgItem(hDlg, IDC_RADIO3);
			SetWindowText(hQ, questions[num].answers[3].c_str());
			hQ = GetDlgItem(hDlg, IDC_RADIO4);
			SetWindowText(hQ, questions[num].answers[4].c_str());
			}
		if(LOWORD(wParam) == IDC_BUTTON2)
			if(num > 0)
			{
				num--;
				SetWindowText(hEdit, questions[num].text.c_str());
			SetWindowText(hEdit, questions[num].text.c_str());
			hQ = GetDlgItem(hDlg, IDC_RADIO1);
			SetWindowText(hQ, questions[num].answers[1].c_str());
			hQ = GetDlgItem(hDlg, IDC_RADIO2);
			SetWindowText(hQ, questions[num].answers[2].c_str());
			hQ = GetDlgItem(hDlg, IDC_RADIO3);
			SetWindowText(hQ, questions[num].answers[3].c_str());
			hQ = GetDlgItem(hDlg, IDC_RADIO4);
			SetWindowText(hQ, questions[num].answers[4].c_str());
			}
		if(LOWORD(wParam) == IDC_BUTTON3)
		{
			DialogBox(hinst, MAKEINTRESOURCE(IDD_DIALOG2), NULL, DlgProc1);
		}
		if(LOWORD(wParam) == IDC_RADIO1)
			CheckRadioButton(hDlg, 1005, 1008, 1005);
		if(LOWORD(wParam) == IDC_RADIO2)
			CheckRadioButton(hDlg, 1005, 1008, 1006);
		if(LOWORD(wParam) == IDC_RADIO3)
			CheckRadioButton(hDlg, 1005, 1008, 1007);
		if(LOWORD(wParam) == IDC_RADIO4)
			CheckRadioButton(hDlg, 1005, 1008, 1008);
		if(LOWORD(wParam) == IDC_BUTTON4)
		{
			//char buf[5];
			//itoa(questions[num].correct_answer,buf,10);
			//MessageBox(hDlg, buf, "Correct", MB_OK);
			hQ = GetDlgItem(hDlg, 1004 + questions[num].correct_answer);
			if(SendMessage(hQ, BM_GETCHECK, 0, 0L))
				MessageBox(hDlg, "Congratuations!", "Correct", MB_OK);
			else
				MessageBox(hDlg, questions[num].answers[questions[num].correct_answer].c_str(), "Wrong. Correct is", MB_OK);
		}
		break;
	}
	return (INT_PTR)FALSE;
}
