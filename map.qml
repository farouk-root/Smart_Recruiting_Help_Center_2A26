import QtQuick 2.0
import QtQuick.Window 2.0
import QtLocation 5.6
import QtPositioning 5.6

Window {
    width: 1000
    height: 850
    visible: true

    Plugin {
        id: mapPlugin
        name: "osm" // "mapboxgl", "esri", ...
        PluginParameter {
                   name: "osm.mapping.providersrepository.disabled"
                   value: "true"
               }
               PluginParameter {
                   name: "osm.mapping.providersrepository.address"
                   value: "http://maps-redirect.qt.io/osm/5.6/"
               }
    }

    Map {
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(36.839448552924246, 10.300041682114815) // Oslo
        zoomLevel: 14
    }
}

