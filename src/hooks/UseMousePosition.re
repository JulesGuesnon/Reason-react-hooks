open Utils.Dom;

type mousePosition = {
  x: float,
  y: float,
};
[@bs.val] external window: Dom.element = "window";

let useMousePositon = () => {
  let (mousePosition, setMousePosition) =
    React.useState(_ => {x: 0., y: 0.});

  let handleMouseMove = e =>
    setMousePosition(_ => {x: e##clientX, y: e##clientY});

  React.useEffect1(
    _ => {
      window->addEventListener("mousemove", handleMouseMove);
      Some(() => window->removeEventListener("mousemove", handleMouseMove));
    },
    [||],
  );

  mousePosition;
};