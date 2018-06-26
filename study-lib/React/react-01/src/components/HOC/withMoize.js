import moize from "moize";

export function withMoize(Component) {
  return moize.react(Component)
}