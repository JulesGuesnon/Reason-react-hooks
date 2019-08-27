open Utils.Dom;

let useHover = () => {
  let (isHovered, setIsHovered) = React.useState(() => false);
  let ref = React.useRef(Js.Nullable.null);

  let onMouseOver = () => setIsHovered(_ => true);
  let onMouseOut = () => setIsHovered(_ => false);

  React.useEffect1(
    () => {
      ref
      ->Utils.optionFromRef
      ->Belt.Option.map(ref => {
          let node = ref->findDOMNode;
          node->addEventListener("mouseenter", onMouseOver);
          node->addEventListener("mouseleave", onMouseOut);
        })
      ->ignore;
      Some(
        () =>
          ref
          ->Utils.optionFromRef
          ->Belt.Option.map(ref => {
              let node = ref->findDOMNode;
              node->removeEventListener("mouseenter", onMouseOver);
              node->removeEventListener("mouseleave", onMouseOut);
            })
          ->ignore,
      );
    },
    [|ref->React.Ref.current|],
  );

  (ReactDOMRe.Ref.domRef(ref), isHovered);
};