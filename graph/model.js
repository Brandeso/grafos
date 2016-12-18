(function () {
    var adjacencyMatrix = null;
    var CLR = [
        "#b2b19d",
        "orange",
        "#922E00",
        "#a7af00",
        'red'
    ];

    return Matrix = {
        getFromFile: function (callback) {
            var fileInput = $('#fileInput');
            fileInput.on('change', function (e) {
                var file = fileInput[0].files[0];
                var textType = /text.*/;

                if (file.type.match(textType)) {
                    var reader = new FileReader();

                    reader.onload = function(e) {
                        var text=reader.result;
                        var matrix = text.split("\n");
                        adjacencyMatrix = matrix.map(function (element) {
                            return element.split(',').map(function(x){return parseInt(x);})
                        });

                        callback({
                            nodes: Matrix.getNodes(),
                            edges: Matrix.getEdges()
                        })

                    };

                    reader.readAsText(file);
                } else {
                    aler("File not supported!");
                    return false
                }
            });

        },

        getFromStatic: function (callback) {
            adjacencyMatrix = [
                [0, 1, 0, 0, 1, 0],
                [1, 0, 1, 0, 1, 0],
                [0, 1, 0, 1, 0, 0],
                [0, 0, 1, 0, 1, 1],
                [1, 1, 0, 1, 0, 0],
                [0, 1, 0, 1, 0, 1]
            ];
            callback({
                nodes: Matrix.getNodes(),
                edges: Matrix.getEdges()
            })
        },

        getEdges: function () {
            var count = 0;
            var countNodes = 0;

            return adjacencyMatrix.reduce(function(map, obj){
                countNodes = 0;
                map['V' + count] = obj.reduce(function(mapEdges, node){
                    if (node >= 1)
                        mapEdges['V' + countNodes] = {};
                    countNodes++;
                    return mapEdges;

                }, {});
                count++;
                return map;
            },{});
        },

        getNodes: function () {
            if (!adjacencyMatrix){
                alert('Use either getFromFile or getStatic first');
                return false;
            }

            var count = 0;
            return adjacencyMatrix.reduce(function(map, obj){
                map['V' + count] = {color:CLR[Math.floor(Math.random() * CLR.length)], shape:"dot", alpha:1, link:'#reference'};
                count++;
                return map;
            },{});


        }
    }
})();