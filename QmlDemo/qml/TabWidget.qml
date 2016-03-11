import QtQuick 1.1

Rectangle
{
    id: tabwidget
    color: "transparent"

    function currentChanged(curIndex)
    {
        content.currentChanged(curIndex)
    }

    Row
    {
        id: toolbar
        spacing: 12
        anchors.left: tabwidget.left
        anchors.leftMargin: 10
        property int current: 0
        onCurrentChanged:setCurrentToolBtn()

        function setCurrentToolBtn()
        {
            for(var i = 0; i < toolbar.children.length; i++)
            {
                toolbar.children[i].state = (toolbar.current == i ? 'checked' : 'leave')
            }
            tabwidget.currentChanged(toolbar.current)
        }

        ToolBtn
        {
            index:0
            state:"checked"
            picSrc: "Image/ico_Examine.png"
            btnText:"电脑体检"
            onClicked:toolbar.current=btnIndex
        }
        ToolBtn
        {
            index:1
            picSrc: "Image/ico_dsmain.png"
            btnText:"木马查杀"
            onClicked:toolbar.current=btnIndex
        }
        ToolBtn
        {
            index:2
            picSrc: "Image/ico_SysRepair.png"
            btnText:"系统修复"
            onClicked:toolbar.current=btnIndex
        }
        ToolBtn
        {
            index:3
            picSrc: "Image/ico_TraceCleaner.png"
            btnText:"电脑清理"
            onClicked:toolbar.current=btnIndex
        }
        ToolBtn
        {
            index:4
            picSrc: "Image/ico_SpeedupOpt.png"
            btnText:"优化加速"
            onClicked:toolbar.current=btnIndex
        }
        ToolBtn
        {
            index:5
            picSrc: "Image/ico_expert.png"
            btnText:"电脑专家"
            onClicked:toolbar.current=btnIndex
        }
        ToolBtn
        {
            index:6
            picSrc: "Image/ico_diannaomenzhen.png"
            btnText:"电脑门诊"
            onClicked:toolbar.current=btnIndex
        }
        ToolBtn
        {
            index:7
            picSrc: "Image/ico_softmgr.png"
            btnText:"软件管家"
            onClicked:toolbar.current=btnIndex
        }
    }

    Rectangle
    {
        id:content
        width:tabwidget.width
        anchors.top: toolbar.bottom
        anchors.topMargin: -5
        height: 500
        color:"white"

        property int current: 0

        function currentChanged(curIndex)
        {
            content.children[curIndex].x=width
            content.children[curIndex].state='active'
            content.children[current].state='hide'
            current = curIndex
        }

        MainWidget
        {
            id:widget1
            state:"active"

            Content1
            {
            }
        }
        MainWidget
        {
            Rectangle
            {
                anchors.fill: parent
                anchors.margins: 50
                color:"#99FF0000"
                Text
                {
                    font.pointSize: 50
                    font.family: "微软雅黑"
                    color:"#FFFFFF"
                    anchors.centerIn: parent
                    text:"十步杀一人"
                }
            }
        }
        MainWidget
        {
            Rectangle
            {
                anchors.fill: parent
                anchors.margins: 50
                color:"#BB00FF00"
                Text
                {
                    font.pointSize: 100
                    font.family: "微软雅黑"
                    color:"#FFFFFF"
                    anchors.centerIn: parent
                    text:"，"
                }
            }
        }
        MainWidget
        {
            Rectangle
            {
                anchors.fill: parent
                anchors.margins: 50
                color:"#990000FF"
                Text
                {
                    font.pointSize: 50
                    font.family: "微软雅黑"
                    color:"#FFFFFF"
                    anchors.centerIn: parent
                    text:"千里不留行"
                }
            }
        }
        MainWidget
        {
            Rectangle
            {
                anchors.fill: parent
                anchors.margins: 50
                color:"#FFFF9900"
                Text
                {
                    font.pointSize: 50
                    font.family: "微软雅黑"
                    color:"#FFFFFF"
                    anchors.centerIn: parent
                    text:"。"
                }
            }
        }
        MainWidget
        {
            Rectangle
            {
                anchors.fill: parent
                anchors.margins: 50
                color:"#FF00FFFF"
                Text
                {
                    font.pointSize: 50
                    font.family: "微软雅黑"
                    color:"#FFFFFF"
                    anchors.centerIn: parent
                    text:"事了拂衣去"
                }
            }
        }
        MainWidget
        {
            Rectangle
            {
                anchors.fill: parent
                anchors.margins: 50
                color:"#99FF00FF"
                Text
                {
                    font.pointSize: 50
                    font.family: "微软雅黑"
                    color:"#FFFFFF"
                    anchors.centerIn: parent
                    text:"，"
                }
            }
        }
        MainWidget
        {
            Rectangle
            {
                anchors.fill: parent
                anchors.margins: 50
                color:"#FFC0C0C0"
                Text
                {
                    font.pointSize: 50
                    font.family: "微软雅黑"
                    color:"#FFFFFF"
                    anchors.centerIn: parent
                    text:"深藏功与名。"
                }
            }
        }
    }
}
