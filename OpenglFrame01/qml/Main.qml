import QtQuick 2.4
import QtQuick.Window 2.2


/* 项目所在触摸屏分辨率：*/
Window {
    id: wmainwindow;
    property int windowWidth: 540
    property int windowHeight: 960

    title: qsTr("虚拟搭配")
    //    flags:Qt.FramelessWindowHint | Qt.WindowSystemMenuHint | Qt.WindowMinimizeButtonHint | Qt.Window
    width: windowWidth
    height: windowHeight
    visible: true
    //    width: Screen.width
    ////    height: Screen.height
    //    height: Screen.desktopAvailableHeight

    color: "transparent"

    Rectangle {
        id: borderrect;
        color: "transparent";
        anchors.fill: parent;

        //开启键盘
        focus: true
        Keys.enabled: true;
        Keys.onEscapePressed:
        {
            Qt.quit();
        }
        Keys.onPressed:
        {
            //            console.log(event.key)
            switch(event.key)
            {
            case Qt.Key_0:
                break;
            default:
                return;
            }
            event.accepted = true;
        }

        // model show
        ModelShow {
            //        Rectangle{
            id: wmodelshow;
            anchors.top: parent.top;
            anchors.bottom: parent.bottom;
            anchors.left: parent.left;
            anchors.right: parent.right;
        }

    }

    Component.onCompleted: {
        console.log(    Screen.desktopAvailableWidth +" "+ Screen.desktopAvailableHeight +" "+ Screen.width +" "+
                    Screen.height )

    }
}
