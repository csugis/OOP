# Microsoft Developer Studio Project File - Name="GISDraw" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=GISDraw - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "GISDraw.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "GISDraw.mak" CFG="GISDraw - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "GISDraw - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "GISDraw - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "GISDraw - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "GISDraw - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "GISDraw - Win32 Release"
# Name "GISDraw - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Arc.cpp
# End Source File
# Begin Source File

SOURCE=.\BaseTool.cpp
# End Source File
# Begin Source File

SOURCE=.\Beeline.cpp
# End Source File
# Begin Source File

SOURCE=.\Curve.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgContents.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSetBkColor.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSetGeo.cpp
# End Source File
# Begin Source File

SOURCE=.\Geometry.cpp
# End Source File
# Begin Source File

SOURCE=.\GISDraw.cpp
# End Source File
# Begin Source File

SOURCE=.\GISDraw.rc
# End Source File
# Begin Source File

SOURCE=.\GISDrawDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\GISDrawView.cpp
# End Source File
# Begin Source File

SOURCE=.\Label.cpp
# End Source File
# Begin Source File

SOURCE=.\Layer.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\Manager.cpp
# End Source File
# Begin Source File

SOURCE=.\Round.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\ToolDelRound.cpp
# End Source File
# Begin Source File

SOURCE=.\ToolDrawCircle.cpp
# End Source File
# Begin Source File

SOURCE=.\ToolDrawFillCircle.cpp
# End Source File
# Begin Source File

SOURCE=.\ToolDrawLine.cpp
# End Source File
# Begin Source File

SOURCE=.\ToolDrawPolygon.cpp
# End Source File
# Begin Source File

SOURCE=.\ToolDrawPolyline.cpp
# End Source File
# Begin Source File

SOURCE=.\ToolDrawText.cpp
# End Source File
# Begin Source File

SOURCE=.\ToolEditFillCircle.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Arc.h
# End Source File
# Begin Source File

SOURCE=.\BaseTool.h
# End Source File
# Begin Source File

SOURCE=.\Beeline.h
# End Source File
# Begin Source File

SOURCE=.\Curve.h
# End Source File
# Begin Source File

SOURCE=.\DlgContents.h
# End Source File
# Begin Source File

SOURCE=.\DlgSetBkColor.h
# End Source File
# Begin Source File

SOURCE=.\DlgSetGeo.h
# End Source File
# Begin Source File

SOURCE=.\Geometry.h
# End Source File
# Begin Source File

SOURCE=.\GISDraw.h
# End Source File
# Begin Source File

SOURCE=.\GISDrawDoc.h
# End Source File
# Begin Source File

SOURCE=.\GISDrawView.h
# End Source File
# Begin Source File

SOURCE=.\Label.h
# End Source File
# Begin Source File

SOURCE=.\Layer.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\Manager.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\Round.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\ToolDelRound.h
# End Source File
# Begin Source File

SOURCE=.\ToolDrawCircle.h
# End Source File
# Begin Source File

SOURCE=.\ToolDrawFillCircle.h
# End Source File
# Begin Source File

SOURCE=.\ToolDrawLine.h
# End Source File
# Begin Source File

SOURCE=.\ToolDrawPolygon.h
# End Source File
# Begin Source File

SOURCE=.\ToolDrawPolyline.h
# End Source File
# Begin Source File

SOURCE=.\ToolDrawText.h
# End Source File
# Begin Source File

SOURCE=.\ToolEditFillCircle.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\GISDraw.ico
# End Source File
# Begin Source File

SOURCE=.\res\GISDraw.rc2
# End Source File
# Begin Source File

SOURCE=.\res\GISDrawDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\picture4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
