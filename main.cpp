#include "stdafx.h"
#include "sxexplorer.h"
#include "sxeditor.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	HANDLE hMutex = CreateMutexA(NULL, true, "sxnote");
	if(GetLastError() == ERROR_ALREADY_EXISTS)
	{
		return 0;
	}


	QString exepath = QApplication::instance()->applicationDirPath();
	QString respath = exepath + "/../";
	respath = QDir::cleanPath(respath);	
	KResource::addSearchPath("res", respath);
	KResource::addSearchPath("res", exepath);

	QString dllpath = KUtility::osExeInstancePath() + "\\imageformats";
	KUtility::CopyVS2008ManifestFiles(dllpath);
	KXmlUI::initSkin("res:/Resources/layout/skins.xml");

	QRect screenRt = KUtility::virtualScreenRect();
	QRect workArea = KUtility::desktopWorkArea();

	SxExplorer explorer;
	int retval = a.exec();
	return retval;
}