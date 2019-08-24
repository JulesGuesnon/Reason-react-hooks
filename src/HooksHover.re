[@bs.module "react-dom"]
external findDOMNode: 'a => Dom.element = "findDOMNode";

[@bs.send]
external addEventListener: (Dom.element, string, unit => unit) => unit =
  "addEventListener";

[@bs.send]
external removeEventListener: (Dom.element, string, unit => unit) => unit =
  "removeEventListener";

let optionFromRef = ref => ref->React.Ref.current->Js.Nullable.toOption;

let useHover = () => {
  let (isHovered, setIsHovered) = React.useState(() => false);
  let ref = React.useRef(Js.Nullable.null);

  let onMouseOver = () => setIsHovered(_ => true);
  let onMouseOut = () => setIsHovered(_ => false);

  React.useEffect1(
    () => {
      ref
      ->optionFromRef
      ->Belt.Option.map(ref => {
          let node = ref->findDOMNode;
          node->addEventListener("mouseenter", onMouseOver);
          node->addEventListener("mouseleave", onMouseOut);
        })
      ->ignore;
      Some(
        () =>
          ref
          ->optionFromRef
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