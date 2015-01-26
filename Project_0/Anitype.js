Anitype.register('S', {

  author: 'sam ticknor',
  website: 'http://samanthaticknor.com/',

  construct: function(two, points) {
  
  var anitype = this;

  // Create a Two.Polygon
  var polygon = anitype.makePolygon(points);
    
  // Adding and adjusting vertices
  polygon.vertices[0].y = -190;
  polygon.vertices[0].command = Two.Commands.curve;
  polygon.vertices[0].controls.left.y = -170; 
  polygon.vertices[0].controls.right.y = -240;
  polygon.vertices[1].controls.left.x = 170;
  polygon.vertices[3].x = 0;
  polygon.vertices[3].y = 0;    
  polygon.vertices[3].controls.left.y = 0;
  polygon.vertices[3].controls.right.y = 0;
  polygon.vertices[6].x = -polygon.vertices[4].x;
  polygon.vertices[6].y = polygon.vertices[4].y;
  polygon.vertices[6].command = Two.Commands.curve;
  polygon.vertices[6].controls.right.y = 133;
  polygon.vertices[6].controls.left.y = 261;
  polygon.vertices.push(polygon.vertices[3].clone());
  polygon.vertices[7].command = Two.Commands.curve;
  // Add second set of same vertices so path can wrap
  polygon.vertices.push(polygon.vertices[0].clone());
  polygon.vertices.push(polygon.vertices[1].clone());
  polygon.vertices.push(polygon.vertices[2].clone());
  polygon.vertices.push(polygon.vertices[3].clone());
  polygon.vertices.push(polygon.vertices[4].clone());
  polygon.vertices.push(polygon.vertices[5].clone());
  polygon.vertices.push(polygon.vertices[6].clone());
  polygon.vertices.push(polygon.vertices[7].clone());

  // Animation
  
  polygon.beginning = .03;
  polygon.subdivide([2]);
  polygon.ending = .4;
    
  anitype.addTween(polygon, {
    to: { ending: .93 },
    duration: .6,
    start: .3,
    easing: Anitype.Easing.Linear.In,
  });

  anitype.addTween(polygon, {
    to: { beginning: .56 },
    duration: .6,
    start: .3,
    easing: Anitype.Easing.Linear.In,
  });

  // Return your polygon wrapped in a group.
  return two.makeGroup(polygon);
  
  }
});
