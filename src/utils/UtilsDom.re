[@bs.module "react-dom"]
external findDOMNode: 'a => Dom.element = "findDOMNode";

[@bs.send]
external addEventListener: (Dom.element, string, unit => unit) => unit =
  "addEventListener";

[@bs.send]
external removeEventListener: (Dom.element, string, unit => unit) => unit =
  "removeEventListener";