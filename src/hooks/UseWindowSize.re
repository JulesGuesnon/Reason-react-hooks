open Utils.Dom;

type size = {
  width: float,
  height: float,
};

[@bs.val] external window: Dom.element = "window";
[@bs.val] [@bs.scope "window"] external innerHeight: float = "innerHeight";
[@bs.val] [@bs.scope "window"] external innerWidth: float = "innerWidth";

let useWindowSize = () => {
  let (size, setSize) =
    React.useState(() => {width: innerWidth, height: innerHeight});

  let handleResize = _ =>
    setSize(_ => {width: innerWidth, height: innerHeight});

  React.useEffect1(
    () => {
      window->addEventListener("resize", handleResize);

      Some(() => window->removeEventListener("resize", handleResize));
    },
    [||],
  );
  size;
};