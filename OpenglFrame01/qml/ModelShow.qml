import QtQuick 2.4
import QMLOglContainer 1.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.2

Rectangle {
    id: models;
//    color: "#011020";
//    color: "#CCCCCC"
    color: "transparent"
    property alias mode: oglContainer;

    function resetView()
    {
        oglContainer.resetArcView();
    }

    Rectangle {
        id: modelshow_3dboard;
        anchors.fill: parent;
        color: "white";
        visible: true;

        QMLOglContainer {
            id: oglContainer;
            anchors.fill: parent;
            viewPortWidth: modelshow_3dboard.width;
            viewPortHeight: modelshow_3dboard.height;

            MouseArea {
                id: modeMouseArea;
                hoverEnabled: true
                anchors.fill: parent
                acceptedButtons: Qt.LeftButton | Qt.RightButton | Qt.MidButton;
                property point pos: "0,0";
                property point lastPos: "0,0";
                property point lastPos2: "0,0";
                property real zoomSpeed: 8.0;

                onPressed: {
                    lastPos  = Qt.point(mouseX, mouseY);
                    lastPos2  = Qt.point(mouseX, mouseY);

                }

                onReleased: {
                    lastPos  = Qt.point(0, 0);
                    lastPos2  = Qt.point(0, 0);
                }


                onPositionChanged: {
                    pos = Qt.point(mouseX, mouseY);
                    if (modeMouseArea.pressed)
                    {
                        var dx = mouseX - lastPos.x;
                        var dy = mouseY - lastPos.y;

                        lastPos = Qt.point(mouseX, mouseY);
                    }
                    else
                    {

                    }
                }

                onWheel:
                {

                }
            }

        }


    }
}
