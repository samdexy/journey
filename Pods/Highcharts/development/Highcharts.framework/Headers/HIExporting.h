/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIButtons.h"
#import "HICsv.h"
#import "HIFunction.h"


/**
Options for the exporting module. For an overview on the matter, see [the docs](http://www.highcharts.com/docs/export-module/export-module-overview).
*/
@interface HIExporting: HIChartsJSONSerializable

/**
An object consisting of definitions for the menu items in the context menu. Each key value pair has a `key` that is referenced in the `menuItems` setting, and a `value`, which is an object with the following properties:  onclick The click handler for the menu item text The text for the menu item textKey If internationalization is required, the key to a language string  

**Try it**

* [Menu item definitions](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/exporting/menuitemdefinitions/)
*/
@property(nonatomic, readwrite) id menuItemDefinitions;
/**
Analogous to `sourceWidth`.
*/
@property(nonatomic, readwrite) NSNumber *sourceHeight;
/**
The width of the original chart when exported, unless an explicit `chart.width` is set. The width exported raster image is then multiplied by `scale`.

**Try it**

* [Source size demo](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/exporting/sourcewidth/)
*/
@property(nonatomic, readwrite) NSNumber *sourceWidth;
/**
Defines the scale or zoom factor for the exported image compared to the on-screen display. While for instance a 600px wide chart may look good on a website, it will look bad in print. The default scale of 2 makes this chart export to a 1200px PNG or JPG.

**Try it**

* [Scale demonstrated](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/exporting/scale/)
*/
@property(nonatomic, readwrite) NSNumber *scale;
/**
Export-data module required. Show a HTML table below the chart with the chart's current data.

**Try it**

* [Show the table](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/export-data/showtable/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *showTable;
/**
The filename, without extension, to use for the exported chart.

**Defaults to** `chart`.

**Try it**

* [Custom file name](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/exporting/filename/)
*/
@property(nonatomic, readwrite) NSString *filename;
/**
Options for the export related buttons, print and export. In addition to the default buttons listed here, custom buttons can be added. See `navigation.buttonOptions` for general options.
*/
@property(nonatomic, readwrite) HIButtons *buttons;
/**
The pixel width of charts exported to PNG or JPG. As of Highcharts 3.0, the default pixel width is a function of the `chart.width` or `exporting.sourceWidth` and the `exporting.scale`.

**Defaults to** `undefined`.

**Try it**

* [Export to 200px wide images](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/exporting/width/)
*/
@property(nonatomic, readwrite) NSNumber *width;
/**
When printing the chart from the menu item in the burger menu, if the on-screen chart exceeds this width, it is resized. After printing or cancelled, it is restored. The default width makes the chart fit into typical paper format. Note that this does not affect the chart when printing the web page as a whole.

**Defaults to** `780`.
*/
@property(nonatomic, readwrite) NSNumber *printMaxWidth;
/**
Options for exporting data to CSV or ExCel, or displaying the data in a HTML table or a JavaScript structure. Requires the `export-data.js` module. This module adds data export options to the export menu and provides functions like `Chart.getCSV`, `Chart.getTable`, `Chart.getDataRows` and `Chart.viewData`.

**Try it**

* [Categorized data](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/export-data/categorized/)
* [Highstock time axis](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/export-data/stock-timeaxis/)
*/
@property(nonatomic, readwrite) HICsv *csv;
/**
Default MIME type for exporting if `chart.exportChart()` is called without specifying a `type` option. Possible values are `image/png`, `image/jpeg`, `application/pdf` and `image/svg+xml`.

**Accepted values:** `["image/png", "image/jpeg", "application/pdf", "image/svg+xml"]`.
*/
@property(nonatomic, readwrite) NSString *type;
/**
Additional chart options to be merged into an exported chart. For example, a common use case is to add data labels to improve readability of the exported chart, or to add a printer-friendly color scheme.

**Defaults to** `null`.

**Try it**

* [Added data labels](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/exporting/chartoptions-data-labels/)
*/
@property(nonatomic, readwrite) id chartOptions;
/**
An object containing additional attributes for the POST form that sends the SVG to the export server. For example, a `target` can be set to make sure the generated image is received in another frame, or a custom `enctype` or `encoding` can be set.
*/
@property(nonatomic, readwrite) id formAttributes;
/**
Whether or not to fall back to the export server if the offline-exporting module is unable to export the chart on the client side.

**Defaults to** `true`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *fallbackToExportServer;
/**
Export-data module required. If using multi level table headers, use rowspans for headers that have only one level.

**Try it**

* [Multiple table headers](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/export-data/multilevel-table)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *useRowspanHeaders;
/**
Export-data module required. Use multi level headers in data table. If `csv.columnHeaderFormatter` is defined, it has to return objects in order for multi level headers to work.

**Try it**

* [Multiple table headers](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/export-data/multilevel-table)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *useMultiLevelHeaders;
/**
The URL for the server module converting the SVG string to an image format. By default this points to Highchart's free web service.
*/
@property(nonatomic, readwrite) NSString *url;
/**
Whether to enable the exporting module. Disabling the module will hide the context button, but API methods will still be available.

**Defaults to** `true`.

**Try it**

* [Exporting module is loaded but disabled](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/exporting/enabled-false/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
Experimental setting to allow HTML inside the chart (added through the `useHTML` options), directly in the exported image. This allows you to preserve complicated HTML structures like tables or bi-directional text in exported charts. Disclaimer: The HTML is rendered in a `foreignObject` tag in the generated SVG. The official export server is based on PhantomJS, which supports this, but other SVG clients, like Batik, does not support it. This also applies to downloaded SVG that you want to open in a desktop client.

**Defaults to** `false`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *allowHTML;
/**
Export-data module required. Caption for the data table. Same as chart title by default. Set to `false` to disable.

**Defaults to** `undefined`.

**Try it**

* [Multiple table headers](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/export-data/multilevel-table)
*/
@property(nonatomic, readwrite) id /* Bool, NSString */ tableCaption;
/**
Function to call if the offline-exporting module fails to export a chart on the client side, and `fallbackToExportServer` is disabled. If left undefined, an exception is thrown instead.

**Defaults to** `undefined`.
*/
@property(nonatomic, readwrite) HIFunction *error;
/**
Path where Highcharts will look for export module dependencies to load on demand if they don't already exist on `window`. Should currently point to location of [CanVG](https://github.com/canvg/canvg) library, [RGBColor.js](https://github.com/canvg/canvg), [jsPDF](https://github.com/yWorks/jsPDF) and [svg2pdf.js](https://github.com/yWorks/svg2pdf.js), required for client side export in certain browsers.
*/
@property(nonatomic, readwrite) NSString *libURL;
@property(nonatomic, readwrite) NSString *exportRegionLabel;
@property(nonatomic, readwrite) NSString *menuButtonLabel;
@property(nonatomic, readwrite) NSString *chartMenuLabel;

-(NSDictionary *)getParams;

@end
