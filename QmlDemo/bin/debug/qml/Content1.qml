import QtQuick 1.1
import QtQuick 1.0

Rectangle {
    width:parent.width
    height:parent.height
    color:"transparent"

    Image
    {
        x: 50
        y: 50
        source:"Image/error.png"
    }

    Row
    {
        x: 250
        y: 55

        Text
        {
            color:"black"
            font.pointSize: 13
            font.family: "微软雅黑"
            text:"您的电脑已经 "
        }

        Text
        {
            color:"red"
            font.pointSize: 15
            font.family: "微软雅黑"
            text:"24"
        }

        Text
        {
            color:"black"
            font.pointSize: 13
            font.family: "微软雅黑"
            text:" 天没有体检，建议立即体检！"
        }
    }

    Text
    {
        x:250
        y:100
        color:"#AA000000"
        font.pointSize: 10
        font.family: "微软雅黑"
        text:"系统可能已经存在大量风险，安全性和性能都在急速下降，\n建议您每天坚持电脑体检，提高电脑的安全和性能"
    }

    SysBtn
    {
        x:250
        y:250
        width:166
        height:66
        picNormal: "Image/check_normal.png"
        picHover: "Image/check_hover.png"
        picPressed: "Image/check_pressed.png"
        onClicked:
        {
            console.log("check btn clicked")
        }
    }

    Image {
        id: image1
        x: 650
        y: 10
        source: "Image/register_bg.png"

        AnimatedImage
        {
            fillMode:Image.PreserveAspectFit
            anchors.left: parent.left
            anchors.leftMargin: 100
            source: "Image/panda.gif"
        }
    }



    Row
    {
        x : 665
        y : 145
        spacing:30

        SysBtn
        {
            width:50
            height:45
            picNormal: "Image/firewall_open_normal.png"
            picHover: "Image/firewall_open_hover.png"
            picPressed: "Image/firewall_open_press.png"
        }
        SysBtn
        {
            width:50
            height:45
            picNormal: "Image/guard_open_normal.png"
            picHover: "Image/guard_open_hover.png"
            picPressed: "Image/guard_open_press.png"
        }
        SysBtn
        {
            width:50
            height:45
            picNormal: "Image/payinsure_close_normal.png"
            picHover: "Image/payinsure_close_hover.png"
            picPressed: "Image/payinsure_close_press.png"
        }
    }

    Row
    {
        x: 658
        y: 190
        spacing: 32

        Text
        {
            color:"#AA000000"
            font.pointSize: 9
            font.family: "微软雅黑"
            text:"木马防火墙"
        }
        Text
        {
            color:"#AA000000"
            font.pointSize: 9
            font.family: "微软雅黑"
            text:"360保镖"
        }
        Text
        {
            color:"#AA000000"
            font.pointSize: 9
            font.family: "微软雅黑"
            text:"网购先赔"
        }
    }

    Rectangle
    {
        x: 645
        y: 0
        width:1
        height:parent.height
        color:"#BBBBBB"
    }

    Rectangle
    {
        x: 645
        y: 130
        width:260
        height:1
        color:"#BBBBBB"
    }

    Rectangle
    {
        x: 645
        y: 220
        width:260
        height:1
        color:"#BBBBBB"
    }

    Rectangle
    {
        x: 645+85
        y: 130
        width:1
        height:90
        color:"#BBBBBB"
    }

    Rectangle
    {
        x: 645+85*2
        y: 130
        width:1
        height:90
        color:"#BBBBBB"
    }

    Grid
    {
        x:680
        y:250
        columns: 3
        rows:3
        spacing:25

        LabelBtn
        {
            picSrc: "Image/net_pretext.png"
            text:"瞒天过海"
        }
        LabelBtn
        {
            picSrc: "Image/mobile.png"
            text:"指桑骂槐"
        }
        LabelBtn
        {
            picSrc: "Image/net_repair.png"
            text:"声东击西"
        }
        LabelBtn
        {
            picSrc: "Image/net_speed.png"
            text:"过河拆桥"
        }
        LabelBtn
        {
            picSrc: "Image/recovery.png"
            text:"趁火打劫"
        }
        LabelBtn
        {
            picSrc: "Image/net_pretext.png"
            text:"以逸待劳"
        }
        LabelBtn
        {
            picSrc: "Image/desktop.png"
            text:"顺手牵羊"
        }
        LabelBtn
        {
            picSrc: "Image/game_box.png"
            text:"借刀杀人"
        }
        LabelBtn
        {
            picSrc: "Image/first_add.png"
            text:"金蝉脱壳"
        }

    }

}
