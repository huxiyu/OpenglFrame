import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.2

/* 项目所在触摸屏分辨率：*/
Window {
    id: wmainwindow
    property int windowWidth: 1500
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
        id: borderrect
        color: "transparent"
        anchors.fill: parent

        //开启键盘
        focus: true
        Keys.enabled: true
        Keys.onEscapePressed:
        {
            Qt.quit()
        }
        Keys.onPressed:
        {
            //            console.log(event.key)
            switch(event.key)
            {
            case Qt.Key_0:
                break
            default:
                return
            }
            event.accepted = true
        }

        // model show
        ModelShow {
            id: wmodelshow
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right
        }

        Text
        {
            id: globalAmbientText
            anchors.left: parent.left
            anchors.top: parent.top
            text: "全局环境光"
            font.family: "Arial"
            font.pixelSize: 12
            color: "#DDDDDD"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        Slider {
            id: globalAmbientR
            anchors.left: parent.left
            anchors.top: globalAmbientText.bottom
            anchors.topMargin: 5
            minimumValue: 0.0
            maximumValue: 1.0
            value: 0.0
            onValueChanged: {
                //                console.log(globalAmbientR.value)
                wmodelshow.mode.globalAmbientR(globalAmbientR.value)
                //                globalAmbientG.value = globalAmbientR.value
            }

        }

        Slider {
            id: globalAmbientG
            anchors.left: parent.left
            anchors.top: globalAmbientR.bottom
            anchors.topMargin: 10
            minimumValue: 0.0
            maximumValue: 1.0
            value: 0.0
            onValueChanged: {
                //                console.log(globalAmbientG.value)
                wmodelshow.mode.globalAmbientG(globalAmbientG.value)
            }
        }

        Slider {
            id: globalAmbientB
            anchors.left: parent.left
            anchors.top: globalAmbientG.bottom
            anchors.topMargin: 10
            minimumValue: 0.0
            maximumValue: 1.0
            value: 0.0
            onValueChanged: {
                //                console.log(globalAmbientB.value)
                wmodelshow.mode.globalAmbientB(globalAmbientB.value)
            }
        }

        Text
        {
            id: matrialAmbientDiffuseText
            anchors.left: parent.left
            anchors.top: globalAmbientB.bottom
            anchors.topMargin: 30
            text: "材料环境光和散射光的反射率(相同的值)"
            font.family: "Arial"
            font.pixelSize: 12
            color: "#DDDDDD"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        Slider {
            id: matrialAmbientDiffuseR
            anchors.left: parent.left
            anchors.top: matrialAmbientDiffuseText.bottom
            anchors.topMargin: 5
            minimumValue: 0.0
            maximumValue: 1.0
            value: 1.0
            onValueChanged: {
                //                console.log(matrialAmbientDiffuseR.value)
                wmodelshow.mode.matrialAmbientDiffuseR(matrialAmbientDiffuseR.value)
            }

        }

        Slider {
            id: matrialAmbientDiffuseG
            anchors.left: parent.left
            anchors.top: matrialAmbientDiffuseR.bottom
            anchors.topMargin: 10
            minimumValue: 0.0
            maximumValue: 1.0
            value: 1.0
            onValueChanged: {
                //                console.log(matrialAmbientDiffuseG.value)
                wmodelshow.mode.matrialAmbientDiffuseG(matrialAmbientDiffuseG.value)
            }
        }

        Slider {
            id: matrialAmbientDiffuseB
            anchors.left: parent.left
            anchors.top: matrialAmbientDiffuseG.bottom
            anchors.topMargin: 10
            minimumValue: 0.0
            maximumValue: 1.0
            value: 1.0
            onValueChanged: {
                //                console.log(matrialAmbientDiffuseB.value)
                wmodelshow.mode.matrialAmbientDiffuseB(matrialAmbientDiffuseB.value)
            }
        }

        Text
        {
            id: matrialSpecularText
            anchors.left: parent.left
            anchors.top: matrialAmbientDiffuseB.bottom
            anchors.topMargin: 30
            text: "材料镜面光的反射率"
            font.family: "Arial"
            font.pixelSize: 12
            color: "#DDDDDD"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        Slider {
            id: matrialSpecularR
            anchors.left: parent.left
            anchors.top: matrialSpecularText.bottom
            anchors.topMargin: 5
            minimumValue: 0.0
            maximumValue: 1.0
            value: 1.0
            onValueChanged: {
                //                console.log(matrialAmbientDiffuseR.value)
                wmodelshow.mode.matrialSpecularR(matrialSpecularR.value)
            }

        }

        Slider {
            id: matrialSpecularG
            anchors.left: parent.left
            anchors.top: matrialSpecularR.bottom
            anchors.topMargin: 10
            minimumValue: 0.0
            maximumValue: 1.0
            value: 1.0
            onValueChanged: {
                wmodelshow.mode.matrialSpecularG(matrialSpecularG.value)
            }
        }

        Slider {
            id: matrialSpecularB
            anchors.left: parent.left
            anchors.top: matrialSpecularG.bottom
            anchors.topMargin: 10
            minimumValue: 0.0
            maximumValue: 1.0
            value: 1.0
            onValueChanged: {
                wmodelshow.mode.matrialSpecularB(matrialSpecularB.value)
            }
        }


        CheckBox
        {
            id: enableLight0
            anchors.left: parent.left
            anchors.top: matrialSpecularB.bottom
            anchors.topMargin: 30
            enabled: true
            checked: false
            style:
                CheckBoxStyle {
                label: Text {
                    //text: "show every launching"
                    text: " 光源0"
                    font.pixelSize: 15
                    font.family: "Arial"
                    font.bold: true
                    color: "green"
                }
            }

            onClicked:
            {
                wmodelshow.mode.enableLight0(enableLight0.checked)
            }
        }

        Text
        {
            id: light0AmbientText
            anchors.left: parent.left
            anchors.top: enableLight0.bottom
            anchors.topMargin: 15
            text: "光源0 -- 环境光"
            font.family: "Arial"
            font.pixelSize: 12
            color: "#DDDDDD"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        Slider {
            id: light0AmbientR
            anchors.left: parent.left
            anchors.top: light0AmbientText.bottom
            anchors.topMargin: 5
            minimumValue: 0.0
            maximumValue: 1.0
            value: 0.0
            onValueChanged: {
                wmodelshow.mode.light0AmbientR(light0AmbientR.value)
            }

        }

        Slider {
            id: light0AmbientG
            anchors.left: parent.left
            anchors.top: light0AmbientR.bottom
            anchors.topMargin: 10
            minimumValue: 0.0
            maximumValue: 1.0
            value: 0.0
            onValueChanged: {
                wmodelshow.mode.light0AmbientG(light0AmbientG.value)
            }
        }

        Slider {
            id: light0AmbientB
            anchors.left: parent.left
            anchors.top: light0AmbientG.bottom
            anchors.topMargin: 10
            minimumValue: 0.0
            maximumValue: 1.0
            value: 0.0
            onValueChanged: {
                wmodelshow.mode.light0AmbientB(light0AmbientB.value)
            }
        }

        Text
        {
            id: light0DiffuseText
            anchors.left: parent.left
            anchors.top: light0AmbientB.bottom
            anchors.topMargin: 15
            text: "光源0 -- 散射光"
            font.family: "Arial"
            font.pixelSize: 12
            color: "#DDDDDD"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        Slider {
            id: light0DiffuseR
            anchors.left: parent.left
            anchors.top: light0DiffuseText.bottom
            anchors.topMargin: 5
            minimumValue: 0.0
            maximumValue: 1.0
            value: 0.0
            onValueChanged: {
                wmodelshow.mode.light0DiffuseR(light0DiffuseR.value)
            }

        }

        Slider {
            id: light0DiffuseG
            anchors.left: parent.left
            anchors.top: light0DiffuseR.bottom
            anchors.topMargin: 10
            minimumValue: 0.0
            maximumValue: 1.0
            value: 0.0
            onValueChanged: {
                wmodelshow.mode.light0DiffuseG(light0DiffuseG.value)
            }
        }

        Slider {
            id: light0DiffuseB
            anchors.left: parent.left
            anchors.top: light0DiffuseG.bottom
            anchors.topMargin: 10
            minimumValue: 0.0
            maximumValue: 1.0
            value: 0.0
            onValueChanged: {
                wmodelshow.mode.light0DiffuseB(light0DiffuseB.value)
            }
        }


        Text
        {
            id: light0SpecularText
            anchors.left: parent.left
            anchors.top: light0DiffuseB.bottom
            anchors.topMargin: 15
            text: "光源0 -- 镜面光"
            font.family: "Arial"
            font.pixelSize: 12
            color: "#DDDDDD"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        Slider {
            id: light0SpecularR
            anchors.left: parent.left
            anchors.top: light0SpecularText.bottom
            anchors.topMargin: 5
            minimumValue: 0.0
            maximumValue: 1.0
            value: 0.0
            onValueChanged: {
                wmodelshow.mode.light0SpecularR(light0SpecularR.value)
            }

        }

        Slider {
            id: light0SpecularG
            anchors.left: parent.left
            anchors.top: light0SpecularR.bottom
            anchors.topMargin: 10
            minimumValue: 0.0
            maximumValue: 1.0
            value: 0.0
            onValueChanged: {
                wmodelshow.mode.light0SpecularG(light0SpecularG.value)
            }
        }

        Slider {
            id: light0SpecularB
            anchors.left: parent.left
            anchors.top: light0SpecularG.bottom
            anchors.topMargin: 10
            minimumValue: 0.0
            maximumValue: 1.0
            value: 0.0
            onValueChanged: {
                wmodelshow.mode.light0SpecularB(light0SpecularB.value)
            }
        }


        Text
        {
            id: light0PosText
            anchors.left: parent.left
            anchors.top: light0SpecularB.bottom
            anchors.topMargin: 15
            text: "光源0 -- 位置"
            font.family: "Arial"
            font.pixelSize: 12
            color: "#DDDDDD"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        Slider {
            id: light0PosX
            width: 500
            anchors.left: parent.left
            anchors.top: light0PosText.bottom
            anchors.topMargin: 5
            minimumValue: -10.0
            maximumValue: 10.0
            value: 0.0
            onValueChanged: {
                wmodelshow.mode.light0PosX(light0PosX.value)
            }

        }

        Slider {
            id: light0PosY
            width: 500
            anchors.left: parent.left
            anchors.top: light0PosX.bottom
            anchors.topMargin: 10
            minimumValue: -10.0
            maximumValue: 10.0
            value: 0.0
            onValueChanged: {
                wmodelshow.mode.light0PosY(light0PosY.value)
            }
        }

        Slider {
            id: light0PosZ
            width: 500
            anchors.left: parent.left
            anchors.top: light0PosY.bottom
            anchors.topMargin: 10
            minimumValue: -10.0
            maximumValue: 10.0
            value: 10
            onValueChanged: {
                wmodelshow.mode.light0PosZ(light0PosZ.value)
            }
        }


    }

    Component.onCompleted: {
        console.log(    Screen.desktopAvailableWidth +" "+ Screen.desktopAvailableHeight +" "+ Screen.width +" "+
                    Screen.height )

    }
}
