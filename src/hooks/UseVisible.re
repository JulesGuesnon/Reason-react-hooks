open BsIntersectionObserver;
type t;

[@bs.new] external intersectionObserver: unit => t = "IntersectionObserver";

let useVisible = () => {
  let ref = React.useRef(Js.Nullable.null);
  let (isVisible, setIsVisible) = React.useState(_ => false);
  let observer =
    Create.intersectionObserver(
      ~cb=
        (entries, _) =>
          Belt.Array.map(entries, entry =>
            if (entry.intersectionRatio > 0.) {
              setIsVisible(_ => true);
            } else {
              setIsVisible(_ => false);
            }
          )
          ->ignore,
      ~options=None,
    );

  React.useEffect1(
    () => {
      ref
      ->Utils.optionFromRef
      ->Belt.Option.map(ref => observer.observe(ref))
      ->ignore;
      Some(
        () =>
          ref
          ->Utils.optionFromRef
          ->Belt.Option.map(ref => {
              observer.unobserve(ref);
              ();
            })
          ->ignore,
      );
    },
    [|ref->React.Ref.current|],
  );

  (ReactDOMRe.Ref.domRef(ref), isVisible);
};