; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CGISDrawView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "GISDraw.h"
LastPage=0

ClassCount=8
Class1=CGISDrawApp
Class2=CGISDrawDoc
Class3=CGISDrawView
Class4=CMainFrame

ResourceCount=5
Resource1=IDD_ABOUTBOX
Class5=CAboutDlg
Resource2=IDR_MAINFRAME
Class6=CDlgSetBkColor
Resource3=IDD_BKCOLOR
Class7=CDlgContents
Resource4=IDD_CONTENTS
Class8=CDlgSetGeo
Resource5=IDD_SETGEOMETRY

[CLS:CGISDrawApp]
Type=0
HeaderFile=GISDraw.h
ImplementationFile=GISDraw.cpp
Filter=N

[CLS:CGISDrawDoc]
Type=0
HeaderFile=GISDrawDoc.h
ImplementationFile=GISDrawDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=CGISDrawDoc

[CLS:CGISDrawView]
Type=0
HeaderFile=GISDrawView.h
ImplementationFile=GISDrawView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CGISDrawView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_TEXT
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=GISDraw.cpp
ImplementationFile=GISDraw.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342308480
Control2=IDC_STATIC,static,1342308352
Control3=IDOK,button,1342373889
Control4=IDC_STATIC,static,1342177294

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_TEST
Command15=ID_VIEW_TOOLBAR
Command16=ID_VIEW_STATUS_BAR
Command17=ID_BK_COLOR
Command18=ID_TABLE_CONTENTS
Command19=ID_SET_GEOMETRY
Command20=ID_APP_ABOUT
CommandCount=20

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=ID_DRAW_TEXT
Command10=ID_DRAW_BEELINE
Command11=ID_DRAW_POLYLINE
Command12=ID_DRAW_CIRCLE
Command13=ID_DRAW_ARC
Command14=ID_DRAW_CIRCLE_FILL
Command15=ID_DRAW_POLYGON
Command16=ID_TEST
Command17=ID_DELETE_TOOL
Command18=ID_EDIT_FILL_CIRCLE
Command19=ID_MOVE_CIRCLE
Command20=ID_DEL_FILL_CIRCLE
Command21=ID_DEL_CIRCLE
Command22=ID_TEXT
CommandCount=22

[DLG:IDD_BKCOLOR]
Type=1
Class=CDlgSetBkColor
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDC_SLIDER_RED,msctls_trackbar32,1342242840
Control3=IDC_SLIDER_GREEN,msctls_trackbar32,1342242840
Control4=IDC_SLIDER_BLUE,msctls_trackbar32,1342242840
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC_RED,static,1342308352
Control9=IDC_STATIC_GREEN,static,1342308352
Control10=IDC_STATIC_BLUE,static,1342308352

[CLS:CDlgSetBkColor]
Type=0
HeaderFile=DlgSetBkColor.h
ImplementationFile=DlgSetBkColor.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgSetBkColor
VirtualFilter=dWC

[CLS:CDlgContents]
Type=0
HeaderFile=DlgContents.h
ImplementationFile=DlgContents.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDlgContents

[DLG:IDD_CONTENTS]
Type=1
Class=CDlgContents
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_TREE_CONTENTS,SysTreeView32,1350631431

[DLG:IDD_SETGEOMETRY]
Type=1
Class=CDlgSetGeo
ControlCount=27
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,button,1342177287
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STYLE,combobox,1344339970
Control8=IDC_WIDTH,edit,1350631552
Control9=IDC_PEN_RED,edit,1350631552
Control10=IDC_PEN_GREEN,edit,1350631552
Control11=IDC_PEN_BLUE,edit,1350631552
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_BRUSH_RED,edit,1350631552
Control16=IDC_BRUSH_GREEN,edit,1350631552
Control17=IDC_BRUSH_BLUE,edit,1350631552
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC,static,1342308352
Control21=IDC_SPIN_PEN_RED,msctls_updown32,1342177314
Control22=IDC_SPIN_BRUSH_RED,msctls_updown32,1342177314
Control23=IDC_SPIN_PEN_GREEN,msctls_updown32,1342177314
Control24=IDC_SPIN_BRUSH_GREEN,msctls_updown32,1342177314
Control25=IDC_SPIN_WIDTH,msctls_updown32,1342177314
Control26=IDC_SPIN_PEN_BLUE,msctls_updown32,1342177314
Control27=IDC_SPIN_BRUSH_BLUE,msctls_updown32,1342177314

[CLS:CDlgSetGeo]
Type=0
HeaderFile=DlgSetGeo.h
ImplementationFile=DlgSetGeo.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgSetGeo
VirtualFilter=dWC

