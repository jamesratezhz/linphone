import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import 'qrc:/ui/components/contact'
import 'qrc:/ui/components/image'
import 'qrc:/ui/components/view'

ColumnLayout {
    id: item

    property var model

    Row {
        Layout.preferredHeight: 35
        spacing: 30

        Icon {
            iconSize: 20
        }

        Text {
            color: '#5A585B'
            font.pointSize: 13
            height: parent.height
            text: qsTr('timelineTitle')
            verticalAlignment: Text.AlignVCenter
        }
    }

    Rectangle {
        Layout.fillWidth: true
        Layout.preferredHeight: 1
        color: '#DEDEDE'
    }

    ScrollableListView {
        Layout.fillHeight: true
        Layout.fillWidth: true

        model: item.model

        delegate: Contact {
            presence: $presence
            sipAddress: $sipAddress
            username: $username
            width: parent.width
        }
    }
}