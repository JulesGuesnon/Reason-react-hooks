[@bs.module "react-dom"]
external findDOMNode: 'a => Dom.element = "findDOMNode";

[@bs.send]
external addEventListener: (Dom.element, string, Js.t('event) => unit) => unit =
  "addEventListener";

[@bs.send]
external removeEventListener:
  (Dom.element, string, Js.t('event) => unit) => unit =
  "removeEventListener";