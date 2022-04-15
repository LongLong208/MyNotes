function draw(id, f = i=>i, title, D = [-5, 5], step = 0.1) {
    let TESTER = document.getElementById(id)
    let x = []
    let y = []
    for (let i = D[0]; i < D[1]; i += step) {
        x.push(i)
        y.push(f(i));
    }
    Plotly.plot(TESTER, [{
        x: x,
        y: y
    }],  { 
        title: title,
        xaxis: {
            showgrid: false,
            ticktext: [],
            tickvals: []
        },
        yaxis: {
            showgrid: false,
            ticktext: [],
            tickvals: []
        }
    })

}

